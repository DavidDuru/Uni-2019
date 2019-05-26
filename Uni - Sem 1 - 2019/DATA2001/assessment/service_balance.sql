--================================================================--
--  Create new 'businesses' table
--================================================================--
drop table businesses

CREATE TABLE businesses(
	area_id NUMERIC PRIMARY KEY
	, num_businesses INTEGER
	, sum_of_relevant INTEGER
	, service_balance numeric
	, avg_service_balance numeric
	, stddev_service_balance numeric
	, z_service_balance NUMERIC
);

-- fill in area_id from neighbourhoods
INSERT INTO businesses(area_id, num_businesses, sum_of_relevant)
SELECT 
	area_id
	, num_businesses
	, (
		retail_trade
		+ accommodation_and_food_services
		+ health_care_and_social_assistance
		+ education_and_training
		+ arts_and_recreation_services
		) as "sum_of_relevant"
FROM businessstats

select * from businesses
order by 2

--  Fill in service_balance (with appropriate value)
UPDATE businesses
SET service_balance = cast(sum_of_relevant as numeric)/num_businesses
where num_businesses > 0
update businesses
set service_balance = 0
where num_businesses = 0

--  Fill in avg_service_balance (with appropriate value)
UPDATE businesses
SET avg_service_balance = (SELECT AVG(service_balance) FROM businesses)

--  Fill in stddev_service_balance (with appropriate value)
UPDATE businesses
SET stddev_service_balance = (SELECT STDDEV(service_balance) FROM businesses)

--  Fill in z_service_balance (with appropriate value)
UPDATE businesses
SET z_service_balance = ((service_balance - avg_service_balance)/stddev_service_balance)
where service_balance is not null

--  Print it out (to check it worked)
SELECT * FROM businesses