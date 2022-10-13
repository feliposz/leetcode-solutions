# Write your MySQL query statement below
select Department, Employee, Salary from 
(
    select d.name as Department,
        e.name as Employee,
        e.salary as Salary, 
        dense_rank() over (partition by departmentId order by salary desc) as r
    from Employee e
    join Department d on e.departmentId = d.id
) x
where r <= 3
order by Salary desc;
