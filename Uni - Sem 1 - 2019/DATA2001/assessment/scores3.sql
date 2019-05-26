drop table scores
--================================================================--
--  Create new 'scores' table
--================================================================--

CREATE TABLE scores(
	area_id NUMERIC PRIMARY KEY
	, area_name VARCHAR
	, cyclability_score NUMERIC
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

-- fill in crime_density from crimes - including NULL
update scores
set crime_density = c.z_crimes_density
from crimes c
where scores.area_id = c.area_id

-- fill in geom
update scores
set boundary = s.geom
from sa2 s
where scores.area_id = s.area_id

-- cyclability
update scores
set cyclability_score = (s.population_density + s.dwelling_density + s.service_balance + s.bikepod_density + s.crime_density)
from scores s
where scores.area_id = s.area_id

-- cyclability where crime is NULL
update scores
set cyclability_score = (s.population_density + s.dwelling_density + s.service_balance + s.bikepod_density)
from scores s
where scores.area_id = s.area_id
	and s.crime_density is NULL

-- add median_income to table
ALTER TABLE scores
ADD COLUMN median_annual_household_income numeric

-- fill it in
update scores
set median_annual_household_income = c.median_annual_household_income
from censusstats c
where scores.area_id = c.area_id

	

SELECT * FROM scores
order by RANDOM()
limit 50






