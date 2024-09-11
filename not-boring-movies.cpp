# Write your MySQL query statement below
select *
from Cinema
where id%2=1
and description!='BORING'
order by rating desc;