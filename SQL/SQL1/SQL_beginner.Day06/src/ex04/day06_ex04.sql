ALTER TABLE person_discounts ADD constraint ch_nn_person_id check(person_id IS NOT NULL);
ALTER TABLE person_discounts ADD CONSTRAINT ch_nn_pizzeria_id CHECK(pizzeria_id IS NOT NULL);
ALTER TABLE person_discounts ADD CONSTRAINT ch_range_discount CHECK (discount IS NOT NULL);
ALTER TABLE person_discounts ALTER COLUMN discount SET DEFAULT 0;
ALTER TABLE person_discounts ADD CONSTRAINT ch_range_discount CHECK (discount between 0 and 100);