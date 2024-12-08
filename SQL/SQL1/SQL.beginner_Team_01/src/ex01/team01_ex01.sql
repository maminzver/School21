-- по требованию readme файла:
-- INSERT INTO currency VALUES (100, 'EUR', 0.85, '2022-01-01 13:29');
-- INSERT INTO currency VALUES (100, 'EUR', 0.79, '2022-01-08 13:29');

-- сам скрипт:
WITH latest_rates AS (
  SELECT DISTINCT ON (id) *
  FROM currency
  ORDER BY id, updated DESC
)
SELECT
  COALESCE(u.name, 'not defined') AS name,
  COALESCE(u.lastname, 'not defined') AS lastname,
  c.name AS currency_name,
  ROUND(b.money * COALESCE(
      (SELECT rate_to_usd
       FROM currency cur
       WHERE cur.id = c.id AND cur.updated <= b.updated
       ORDER BY cur.updated DESC
       LIMIT 1),
      (SELECT rate_to_usd
       FROM currency cur
       WHERE cur.id = c.id AND cur.updated > b.updated
       ORDER BY cur.updated ASC
       LIMIT 1),
      1
  ), 2) AS currency_in_usd
FROM balance b
LEFT JOIN "user" u ON b.user_id = u.id
JOIN latest_rates c ON c.id = b.currency_id
ORDER BY name DESC, lastname, currency_name;