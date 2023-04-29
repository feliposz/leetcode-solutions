with categories as (
    select 'Low Salary' as category, 0 as min_salary, 20000-1 as max_salary
    union
    select 'Average Salary' as category, 20000 as min_salary, 50000 as max_salary
    union
    select 'High Salary' as category, 50001 as min_salary, 999999999 as max_salary
)
select category, count(account_id) as accounts_count
from categories
left join accounts
on income between min_salary and max_salary
group by category