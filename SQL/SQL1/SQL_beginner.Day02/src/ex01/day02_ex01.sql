select gs::date as missing_date
from (select * from person_visits pv where person_id in (1, 2)) as pv right join
generate_series('2022-01-01', '2022-01-10', interval '1 day') as gs on pv.visit_date = gs
where pv.id is null
order by 1