with x as (
    select player_id, min(event_date) as first_login 
    from activity
    group by player_id
)
select round(
    count(distinct if(event_date = date_add(first_login, interval 1 day), player_id, null)) 
    / count(distinct player_id), 2) as fraction
from activity
join x
using (player_id)