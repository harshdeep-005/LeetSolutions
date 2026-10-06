-- # Write your MySQL query statement below
SELECT b.name as Department, a.name as Employee, a.salary as Salary 
FROM Employee as a
JOIN (SELECT d.name, E.departmentId as id, MAX(E.salary) as ma
FROM Employee AS E
JOIN Department as d
ON E.departmentId=d.id
GROUP BY departmentId) as b
ON a.departmentId = b.id
AND a.salary =b.ma;

-- SELECT departmentId, max(salary)
-- FROM Employee
-- GROUP BY departmentId;
