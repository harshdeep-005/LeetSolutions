# Write your MySQL query statement below
SELECT b.name as Employee
FROM Employee as a
JOIN Employee as b
WHERE a.id=b.managerId AND b.salary > a.salary;
