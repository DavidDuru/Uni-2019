TRUNCATE pods;

-- Create new table to join the sa2 with a count of bikepods
CREATE TABLE pods(
	area_id NUMERIC PRIMARY KEY
	, pods INTEGER
	, avg_pods NUMERIC
	, stddev_pods NUMERIC
	, z_pods NUMERIC
	, geom GEOMETRY(Polygon,4326)
);

-- Put the area_id, geom, pods in for all that have pods
insert into pods(area_id, geom, pods);
select area_id, geom, pods from (
				select
					s.area_id
					, s.geom
					, count(*) as "pods"
				from
					sa2 s
					, bikesharingpods b
				where
					ST_CONTAINS(s.geom,b.geom)
				group by
					s.area_id
					, s.geom
				) as "temp_join"

--================================================================--
--  Some stuff might need to go in here to clean up the sa2 boundaries or something?
--================================================================--


-- Put in the other area_id and geoms for those without pods, but with sa2 data
insert into pods(area_id, geom, pods)
select area_id, geom, pods from (
		select
			s.area_id
			, s.geom
			, 0 as "pods"
		from
			censusstats c, sa2 s
		where
			c.area_id = s.area_id
		) as "temp_join"
where temp_join.area_id not in (select area_id from pods)

-- Put in the area_id and pod count (0) for areas without sa2 bounds
insert into pods(area_id, pods)
select area_id, pods from (
	select
		area_id
		, 0 as "pods"
	from censusstats) as "temp_join"
where temp_join.area_id not in (select area_id from pods)


--  Fill in avg_pods (with appropriate value)
UPDATE pods
SET avg_pods = (SELECT AVG(pods) FROM pods)

--  Fill in stddev_pods (with appropriate value)
UPDATE pods
SET stddev_pods = (SELECT STDDEV(pods) FROM pods)

--  Fill in z_service_balance (with appropriate value)
UPDATE pods
SET z_pods = ((pods - avg_pods)/stddev_pods)
where pods is not null

--  Print it out (to check it worked)
SELECT * FROM pods
order by 5 DESC