	for(int i = 0; i < num_files; i++){
		if(strip_these[i].filename[0] == 0){
			sort[j] = strip_these[i];
			j++;
		} else{
			sort[j] = strip_these[i];
			j++;
		}
	}

    	for(int i =0; i < repack_num; i++){
		    printf("%s, %d, %d\n", strip_these[i].filename,strip_these[i].offset,strip_these[i].length);
	    }