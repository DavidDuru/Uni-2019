--================================================================--
--                                                                --
--                        NEIGHBOURHOODS                          --
--                                                                --
--================================================================--

--  Create new table Neighbourhoods2 to modify
CREATE TABLE neighbourhoods2
AS TABLE neighbourhoods


--================================================================--
--  population_density
--================================================================--

--  Alter that table to add population_density column...
ALTER TABLE neighbourhoods2
ADD COLUMN population_density NUMERIC

--  ...then fill it with population_density (population/land_area)
UPDATE neighbourhoods2
SET population_density = population/land_area

--  Add an "avg" column
ALTER TABLE neighbourhoods2
ADD COLUMN avg_population_density NUMERIC

--  ...then fill it (with appropriate value)
UPDATE neighbourhoods2
SET avg_population_density = (SELECT AVG(population_density) FROM neighbourhoods2)

--  Add a "stddev" column
ALTER TABLE neighbourhoods2
ADD COLUMN stddev_population_density NUMERIC

--  ...then fill it (with appropriate value)
UPDATE neighbourhoods2
SET stddev_population_density = (SELECT STDDEV(population_density) FROM neighbourhoods2)

--  Add a "z_score" column
ALTER TABLE neighbourhoods2
ADD COLUMN z_population_density NUMERIC

--  ...then fill it (with appropriate value)
UPDATE neighbourhoods2
SET z_population_density = ((population_density - avg_population_density)/stddev_population_density)


--================================================================--
--  dwelling_density
--================================================================--

--  Alter that table to add dwelling_density column...
ALTER TABLE neighbourhoods2
ADD COLUMN dwelling_density NUMERIC

--  ...then fill it with dwelling_density (number_of_dwellings/land_area)
UPDATE neighbourhoods2
SET dwelling_density = number_of_dwellings/land_area


--  Add an "avg" column
ALTER TABLE neighbourhoods2
ADD COLUMN avg_dwelling_density NUMERIC

--  ...then fill it (with appropriate value)
UPDATE neighbourhoods2
SET avg_dwelling_density = (SELECT AVG(dwelling_density) FROM neighbourhoods2)


--  Add a "stddev" column
ALTER TABLE neighbourhoods2
ADD COLUMN stddev_dwelling_density NUMERIC

--  ...then fill it (with appropriate value)
UPDATE neighbourhoods2
SET stddev_dwelling_density = (SELECT STDDEV(dwelling_density) FROM neighbourhoods2)


--  Add a "z_score" column
ALTER TABLE neighbourhoods2
ADD COLUMN z_dwelling_density NUMERIC

--  ...then fill it (with appropriate value)
UPDATE neighbourhoods2
SET z_dwelling_density = ((dwelling_density - avg_dwelling_density)/stddev_dwelling_density)


--  ...then print it out to prove it was correct.
SELECT *
FROM neighbourhoods2
