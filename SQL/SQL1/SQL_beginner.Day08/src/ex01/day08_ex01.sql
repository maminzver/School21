#SESSION1
BEGIN TRANSACTION ISOLATION LEVEL READ COMMITTED;

#SESSION2
BEGIN TRANSACTION ISOLATION LEVEL READ COMMITTED;

#SESSION1
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';

#SESSION2
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';

#SESSION1
UPDATE pizzeria
SET rating = 4
WHERE name = 'Pizza Hut';

#SESSION2
UPDATE pizzeria
SET rating = 3.6
WHERE name = 'Pizza Hut';

#SESSION1
COMMIT;

#SESSION2
COMMIT

#SESSION1
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut';

#SESSION2
SELECT *
FROM pizzeria
WHERE name = 'Pizza Hut'

