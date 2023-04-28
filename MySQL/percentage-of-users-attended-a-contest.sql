with total as ( select count(*) as user_count from users )
select contest_id, round(count(user_id) / total.user_count * 100, 2) percentage
from total, register r
left join users u
using (user_id)
group by contest_id
order by 2 desc, 1