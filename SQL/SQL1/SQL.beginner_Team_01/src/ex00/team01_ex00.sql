WITH latest_rates AS (
  SELECT DISTINCT ON (id) 
    id, 
    name, 
    rate_to_usd
  FROM currency
  ORDER BY id, updated DESC
), balances AS (
  SELECT user_id,
         type,
         SUM(money) AS volume,
         currency_id
  FROM balance
  GROUP BY user_id, type, currency_id
)
SELECT
  COALESCE(u.name, 'not defined') AS name,
  COALESCE(u.lastname, 'not defined') AS lastname,
  b.type,
  b.volume,
  COALESCE(c.name, 'not defined') AS currency_name,
  COALESCE(c.rate_to_usd, 1) AS last_rate_to_usd,
  ROUND(b.volume * COALESCE(c.rate_to_usd, 1), 2) AS total_volume_in_usd
FROM balances b
LEFT JOIN "user" u ON u.id = b.user_id
LEFT JOIN latest_rates c ON c.id = b.currency_id
ORDER BY 
  name DESC, 
  lastname, 
  type;

