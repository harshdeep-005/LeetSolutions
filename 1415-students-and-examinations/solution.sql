select a.*, s.subject_name, count(e.student_id) as attended_exams
from Students a
cross join Subjects s
left join Examinations e
on a.student_id=e.student_id and s.subject_name=e.subject_name
group by a.student_id,a.student_name, s.subject_name
order by student_id, subject_name


-- select a.*, e.subject_name, count(e.student_id) as attended_exams
-- FROM Students a
-- CROSS JOIN Subjects s
-- LEFT JOIN Examinations e
--     ON a.student_id = e.student_id
--     AND s.subject_name = e.subject_name
-- group by a.student_name, e.subject_name
-- order by student_id, subject_name


