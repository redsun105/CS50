-- Keep a log of any SQL queries you execute as you solve the mystery.
select description from crime_scene_reports
   ...> where year = 2021 and month = 7 and day = 28 and street = "Humphrey Street";

Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
Interviews were conducted today with three witnesses who were present at the time –
each of their interview transcripts mentions the bakery. |
Littering took place at 16:36. No known witnesses.
//
select transcript from interviews
   ...> where year = 2021 and month = 7 and day = 28
   ...> and transcript like "%the bakery%";

Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
If you have security footage from the bakery parking lot,
you might want to look for cars that left the parking lot in that time frame.
                                                          |
As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
The thief then asked the person on the other end of the phone to purchase the flight ticket. |

I'm the bakery owner, and someone came in,
suspiciously whispering into a phone for about half an hour. They never bought anything.

//
select * from bakery_security_logs
   ...> where day = 28 and month = 7 and year = 2021 and hour = 10 and minute <= 25 and minute >= 15;

id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
//
sqlite> select * from phone_calls
   ...> where year = 2021 and month = 7 and day = 28 and duration <= 100;

id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 224 | (499) 555-9472 | (892) 555-8872 | 2021 | 7     | 28  | 36     |
//
sqlite> select * from flights
   ...> where year = 2021 and month = 7 and day =29;
id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |

//
sqlite> select full_name from airports
   ...> where id in (8, 4);
+-----------------------------+
|          full_name          |
+-----------------------------+
| LaGuardia Airport    New York City       |
| Fiftyville Regional Airport |
+-----------------------------+

sqlite> select * from atm_transactions
   ...>  2021 and month = 7 and day = 28 and atm_location = "Humphrey Lane" and transaction_type = "withdraw";
+-----+----------------+------+-------+-----+---------------+------------------+--------+
| id  | account_number | year | month | day | atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+---------------+------------------+--------+
| 245 | 90209473       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 45     |
| 247 | 41935128       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 15     |
| 255 | 66344537       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 55     |
| 258 | 92647903       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 5      |
| 262 | 40665580       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 35     |
| 265 | 96336648       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 20     |
| 273 | 69638157       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 20     |
| 276 | 13156006       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 15     |
| 277 | 89843009       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 40     |
| 280 | 92647903       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 40     |
| 281 | 57022441       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 55     |
| 290 | 79165736       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 5      |
| 291 | 76849114       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 10     |
| 300 | 66344537       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 60     |
| 302 | 50380485       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 100    |
| 309 | 46222318       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 60     |
| 310 | 58673910       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 10     |
| 312 | 93903397       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 35     |
| 315 | 79127781       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 65     |
| 316 | 95773068       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 45     |
| 322 | 26797365       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 35     |
| 329 | 34939061       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 100    |
| 333 | 65190958       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 50     |
| 334 | 99031604       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 20     |
| 337 | 58552019       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 30     |
| 342 | 55322348       | 2021 | 7     | 28  | Humphrey Lane | withdraw         | 5      |
+-----+----------------+------+-------+-----+---------------+------------------+--------+

//
sqlite> select * from people
   ...> where phone_number = "(499) 555-9472";
+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
+--------+--------+----------------+-----------------+---------------+
sqlite> select * from people
   ...> where phone_number = "(892) 555-8872";
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 251693 | Larry | (892) 555-8872 | 2312901747      | O268ZZ0       |
+--------+-------+----------------+-----------------+---------------+

//
sqlite> select * from passengers
   ...> where flight_id = 36 and passport_number in (8294398571, 2312901747);
+-----------+-----------------+------+
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 36        | 8294398571      | 6C   |
+-----------+-----------------+------+