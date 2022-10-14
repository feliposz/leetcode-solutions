# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary
from Employee e
join Department d on e.departmentId = d.id
join ( select departmentId, max(salary) as salary from Employee group by departmentId ) x
on e.departmentId = x.departmentId and e.salary = x.salary