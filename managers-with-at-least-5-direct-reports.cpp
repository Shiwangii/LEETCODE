# Write your MySQL query statement below
select e.name
from Employee e
join(
    select managerId, count(*) as directReports
    From Employee
    group by managerId
    having count(*)>=5
)e2 on e.id=e2.managerId;
