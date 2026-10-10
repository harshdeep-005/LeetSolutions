# Write your MySQL query statement below
select DISTINCT author_id as id
from Views v
where author_id=viewer_id
ORDER BY id asc
