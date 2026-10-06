# Write your MySQL query statement below

SELECT name as Customers
FROM (
SELECT c.name, o.id
FROM Customers AS c
LEFT JOIN Orders AS o
ON c.id=o.customerId
) as temp
WHERE id is NULL;

