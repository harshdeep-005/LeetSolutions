# Write your MySQL query statement below
select machine_id, Round(avg(a),3) processing_time
from(
select machine_id, max(timestamp)-min(timestamp) a
from Activity
group by machine_id, process_id) as t
group by machine_id


