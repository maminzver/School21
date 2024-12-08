WITH RECURSIVE nodes AS (
  SELECT 
    point1 AS path,
    point1, 
    point2, 
    cost
  FROM roads
  WHERE point1 = 'a'   
  UNION 
  SELECT 
    CONCAT(nodes.path, ',', roads.point1) AS path, 
    roads.point1, 
    roads.point2,
    nodes.cost + roads.cost 
  FROM nodes
    JOIN roads ON nodes.point2 = roads.point1
  WHERE path NOT LIKE CONCAT('%', roads.point1, '%') -- обеспечиавет уникальность маршрута
),
routes AS ( -- фтльрация ноедс, и последний шаг
  SELECT 
    cost AS total_cost,
    CONCAT('{', path, ',', point2, '}') AS tour
  FROM nodes
  WHERE LENGTH(path) = 7 AND point2 = 'a'
)

SELECT *
FROM routes
WHERE total_cost = (
  SELECT MIN(total_cost)
  FROM routes
) OR total_cost = (
  SELECT MAX(total_cost)
  FROM routes
)
ORDER BY total_cost, tour;