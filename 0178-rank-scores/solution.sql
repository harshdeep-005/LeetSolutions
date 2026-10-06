# Write your MySQL query statement below
SELECT score, DENSE_Rank() OVER(ORDER BY score DESC) as `rank`
FROM Scores;
