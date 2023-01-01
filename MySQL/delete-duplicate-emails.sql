# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
delete p 
from Person p
join (
    select email, min(id) as id
    from Person
    group by email
) x
on p.email = x.email
where p.id <> x.id