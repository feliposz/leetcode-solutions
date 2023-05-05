select id, count(*) num
from (
select requester_id id, accepter_id other from RequestAccepted
union
select accepter_id id, requester_id other from RequestAccepted
) x
group by id
order by 2 desc
limit 1