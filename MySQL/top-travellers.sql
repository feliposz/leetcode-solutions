# Write your MySQL query statement below
select u.name, sum(IFNULL(distance, 0)) travelled_distance 
from Users u
left join Rides r on r.user_id = u.id
group by u.id, u.name
order by 2 desc, 1 asc