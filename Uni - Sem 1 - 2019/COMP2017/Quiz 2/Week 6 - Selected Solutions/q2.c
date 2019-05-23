#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#define DEFAULT_PKT (10)
#define CONTROLLER_PATH ("controller0")
#define N_RECV_PKT (4)
#define N_HOLD (4)
#define BYTE_SIZE (8)
#define STATE_SIZE (32)
#define N_BUTTONS (16)

//The struct from the gamepad typedef
typedef struct {
  unsigned int id:8;
  unsigned int locked:8;
  unsigned int x:1;
  unsigned int y:1;
  unsigned int z:1;
  unsigned int w:1;
  unsigned int a:1;
  unsigned int b:1;
  unsigned int c:1;
  unsigned int d:1;
  unsigned int l:1;
  unsigned int r:1;
  unsigned int st:1;
  unsigned int sel:1;
  unsigned int pad_1:1;
  unsigned int pad_2:1;
  unsigned int pad_3:1;
  unsigned int pad_4:1;
  float left;
  float right;
} gamepad_data;

//We can map the button index to a list of buttons
const char buttons[][10] = {
	"X", "Y", "Z", "W", "A", "B", "C", "D", "L", "R", "START", "SELECT", 
	"PAD_1", "PAD_2", "PAD_3", "PAD_4" 
};

//We use a union to unpack the data into it
//This allows us to layout the buttons into a 8bit unsigned integer
typedef union {
	struct {
		uint8_t id_bl;
		uint8_t locked_blk;
		uint8_t button_array_1;
		uint8_t button_array_2;
		float left_blk;
		float right_blk;
	} gamepad_unpack;
	gamepad_data data;
} gamepad_pack;


//Unpack the data into an array,
//If you don't want to do this, perform checks with shifts
//This allows you to break down what is occurr and even print out the bits in the packet
void unpack(gamepad_data* data, int* b_map, size_t n) {
	if(b_map != NULL && data != NULL && n >= 16) {
		gamepad_pack pack;
		pack.data = *data;
		for(int i = BYTE_SIZE-1; i >= 0; i--) {
			b_map[i] = pack.gamepad_unpack.button_array_1 & (1 << i);
		}
		for(int i = (BYTE_SIZE*2)-1; i >= BYTE_SIZE; i--) {
			b_map[i] = pack.gamepad_unpack.button_array_2 & (1 << i);
		}
	}
}

/*
 *After we have unpacked the data into a nice array, we can then
 * We can then determine the history of the button states as well as the current button
 * We use this information to then determine if it has been
 * Held, Pressed, Released or nothing
 */
void print_components(int** b_map, size_t n_pkts, size_t n, int pkt_idx) {

	char state[STATE_SIZE];
	int hold = 0;
	size_t label_length = 0;
	for(int i = 0; i < n; i++) {
		label_length = strlen(buttons[i]);
		strcpy(state, buttons[i]);
		strcpy(state+label_length, ": Hold");
		
		hold = 1;
		//Checks hold
		if(pkt_idx >= 3) {
			for(int j = pkt_idx; j >= 0; j--) {
				if(b_map[(j%N_HOLD)][i] == 0) {
					hold = 0;
				}
			}
		} else {
			hold = 0;
		}
		
		//Checks press, or release or nothing
		if(!hold) {
			if(b_map[(pkt_idx%N_HOLD)][i] > 0) {
				strcpy(state+label_length, ": Pressed");
			} else {
				if(pkt_idx >= 1) {
					if(b_map[(pkt_idx-1)%N_HOLD][i] > 0) {
						strcpy(state+label_length, ": Released");
					} else {
						strcpy(state, ""); //Nothing happened on this button
					}
				} else {
					strcpy(state, ""); // Nothing happened because pkt_idx is low
				}
			}
		}
		if(strlen(state) > 0) {
			printf("%s, ", state);
		}
	}
}

//Display the packet
void display_packet(int** b_map, size_t n_pkts, size_t n, int pkt_idx, gamepad_data* pkt) {
	unpack(pkt, b_map[pkt_idx%n_pkts], n);
	printf("PKT%d: ", pkt_idx); 
	print_components(b_map, n_pkts, n, pkt_idx);
	printf("Analog Left: %.4f ", pkt->left);
	printf("Right: %.4f\n", pkt->right); 

}

//Our main function, just gets things started
int main(int argc, char** argv) {
	FILE* f = fopen(CONTROLLER_PATH, "rb");
	int n_pkts = DEFAULT_PKT;
	gamepad_data pkt;
	int i = 0;
	int* b_map[N_RECV_PKT];
	
	for(int i = 0; i < N_RECV_PKT; i++) {
		b_map[i] = malloc(sizeof(int)*N_BUTTONS);
	}
	
	if(argc >= 2) {
		n_pkts = strtol(argv[1], NULL, 10);
	}
	if(f != NULL) {
		while(i < n_pkts) {		
			fread(&pkt, sizeof(gamepad_data), 1, f);
			display_packet(b_map, N_RECV_PKT, N_BUTTONS, i, &pkt);
			i++;
		}
	}
	
	for(int i = 0; i < N_RECV_PKT; i++) {
		free(b_map[i]);
	}
}
