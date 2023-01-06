# Write your MySQL query statement below
select activity_date day, count(DISTINCT(user_id)) active_users
from Activity
where activity_date between date_sub('2019-07-27', interval 29 day) and '2019-07-27'
group by activity_date