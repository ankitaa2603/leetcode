# Write your MySQL query statement below
select round(sum(tiv_2016),2) as tiv_2016 from Insurance
where tiv_2015 in (select tiv_2015 from Insurance
GROUP BY tiv_2015
having count(*)>1)
AND(lat,lon) in (
    SELECT lat,lon from Insurance
    GROUP BY lat, lon having count(*)=1
);