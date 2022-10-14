CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select max(salary)
      from (
          select salary, dense_rank() over (order by salary desc) as r
          from Employee
      ) x
      where x.r = n
  );
END