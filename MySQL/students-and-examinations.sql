# Write your MySQL query statement below
select s.student_id, s.student_name, u.subject_name, count(e.student_id) attended_exams
from students s
cross join subjects u
left join examinations e
on e.subject_name = u.subject_name
and e.student_id = s.student_id
group by s.student_id, s.student_name, u.subject_name
order by 1, 3