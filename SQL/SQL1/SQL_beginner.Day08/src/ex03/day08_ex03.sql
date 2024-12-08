#SESSION1
BEGIN

#SESSION2
BEGIN

#SESSION1
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';

#SESSION2
UPDATE pizzeria
SET rating = 3.6
WHERE name = 'Pizza Hut';

COMMIT;

#SESSION1
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';

COMMIT;

SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut'

#SESSION2
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';