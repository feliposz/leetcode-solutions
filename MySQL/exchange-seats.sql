# Write your MySQL query statement below
select case 
        when mod(id, 2) = 1 and id = (select max(id) from Seat) then id
        when mod(id, 2) = 0 then id - 1 
        else id + 1 
        end as id, student 
from Seat
order by 1
