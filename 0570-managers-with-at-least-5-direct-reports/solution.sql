# Write your MySQL query statement below
-- SELECT name
-- FROM (SELECT a.name, COUNT(b.managerId) as cnt
-- FROM Employee as a
-- JOIN Employee as b
-- ON a.id=b.managerId
-- GROUP BY a.id) AS temp
-- WHERE cnt>4;

SELECT a.name
FROM Employee as a
JOIN Employee as b
ON a.id=b.managerId
GROUP BY a.id
HAVING COUNT(b.managerId) >4;
