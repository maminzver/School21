#SESSION1
BEGIN;

#SESSION2
BEGIN

#SESSION1
UPDATE pizzeria
SET rating = 0
WHERE id = 1;

#SESSION2
UPDATE pizzeria
SET rating = 1
WHERE id = 2;

#SESSION1
UPDATE pizzeria
SET rating = 2
WHERE id = 2;

#SESSION2
UPDATE pizzeria
SET rating = 3
WHERE id = 1;

#SESSION1
COMMIT

#SESSIOIN2
COMMIT