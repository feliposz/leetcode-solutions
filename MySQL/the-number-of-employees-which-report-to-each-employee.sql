select m.employee_id, m.name, count(*) as reports_count, round(avg(e.age)) as average_age
from employees m
join employees e
on m.employee_id = e.reports_to
group by m.employee_id, m.name
order by 1