select object_name
from (
	select name as object_name, 1 as rable_order
	from person
	order by name
) as sorted_person
union all
select object_name
from (
	select pizza_name as object_name, 2 as table_order
	from menu
	order by pizza_name
) as sorted_menu
