    async getEquipmentList({ input }) {
        const test = await db.result('search_equipment_three', input);
        return await db.result('search_equipment_three', input);
    }

    async getEquipmentDetails({ input }) {
        const result = await db.sql('CALL myrso_dev.get_equipment(?,?,@out)', input);
        return result[0][0];
    }
}


input EquipmentFilterInput {
    limit: Int!
    status_code: EquipmentStatus!
    base_equipment_type_code: EquipmentType
    offset: Int!
}

extend type Query {
    equipmentList(input: EquipmentFilterInput!): [Equipment]!
    equipmentDetails(input: Int!): EquipmentDetailsOutput
}


query Equipment {
     equipmentList(input: {limit: 1000 status_code: act offset: 0}) {
     __typename
       reg_due_date
     	equ_id
     	base_equipment_type_code
       base_equipment_type_name
     	status
     	category
     	manufacturer
       account_name
       serial
     	model
     	}
     }