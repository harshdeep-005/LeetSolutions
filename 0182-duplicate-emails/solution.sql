# Write your MySQL query statement below
SELECT email
FROM (SELECT email, COUNT(email) as cnt
        FROM Person
        GROUP BY email) as temp
WHERE cnt>1;
