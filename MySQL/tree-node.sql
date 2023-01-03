# Write your MySQL query statement below
select t.id, 
    case 
        when t.p_id is null then 'Root' 
        when count(c.id) = 0 then 'Leaf'
        else 'Inner'
    end as type
from Tree t
    left join Tree c on t.id = c.p_id
group by t.id, t.p_id