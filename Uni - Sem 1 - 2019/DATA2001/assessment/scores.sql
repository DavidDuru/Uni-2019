--================================================================--
--  Create new 'scores' table
--================================================================--

CREATE TABLE scores(
	area_id NUMERIC PRIMARY KEY
	, area_name VARCHAR
	, population_density NUMERIC
	, dwelling_density NUMERIC
	, service_balance NUMERIC
	, bikepod_density NUMERIC
	, crime_density NUMERIC
	, boundary GEOMETRY(Polygon,4326)
);

-- fill in area_id from neighbourhoods
INSERT INTO scores(area_id)
SELECT area_id FROM neighbourhoods

-- fill in area_name from neighbourhoods
UPDATE scores
SET area_name = n.area_name
FROM neighbourhoods n
WHERE scores.area_id = n.area_id

-- fill in population_density from neighbourhoods2
UPDATE scores
SET population_density = n.z_population_density
FROM neighbourhoods2 n
WHERE scores.area_id = n.area_id

-- fill in population_density from neighbourhoods2
UPDATE scores
SET dwelling_density = n.z_dwelling_density
FROM neighbourhoods2 n
WHERE scores.area_id = n.area_id

-- fill in service_balance from businesses
UPDATE scores
SET service_balance = b.z_service_balance
FROM businesses b
WHERE scores.area_id = b.area_id

-- fill in bikepod_density from pods
update scores
set bikepod_density = p.z_pods
from pods p
where scores.area_id = p.area_id

-- fill in crime_density from lga_crimes ...joined somehow. Hmm..

#SELECT * FROM scores
#order by RANDOM()



scores2 = scores
scores2 = scores2.drop(['cyclability_score', 'boundary'], axis = 1)
scores2['population_density'] = pd.to_numeric(scores2['population_density'])
scores2['dwelling_density'] = pd.to_numeric(scores2['dwelling_density'])
scores2['service_balance'] = pd.to_numeric(scores2['service_balance'])
scores2['bikepod_density'] = pd.to_numeric(scores2['bikepod_density'])

scores2

