#include "doctest.h"
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Team.hpp"
#include "Team2.hpp"
#include "SmartTeam.hpp"

TEST_SUITE("Point class") {
    TEST_CASE("constructors") {
        CHECK_NOTHROW(Point());
        CHECK_NOTHROW(Point(2, 3));
        CHECK_NOTHROW(Point(-1, 5));
        CHECK_NOTHROW(Point(0.5, -2.7));
        CHECK_NOTHROW(Point(-3.9, -8.1));
    }

    TEST_CASE("functions") {
        Point a(1, 2);
        Point b(-3, 4);

        Point a1(2.5, 3.5);
        Point b1(-4.5, 1.5);

        Point a2(-5.7, -2.3);
        Point b2(0.8, -6.4);

        Point a3(9.8, -7.6);
        Point b3(4.2, 3.9);

        SUBCASE("distance") {
            CHECK_NOTHROW(a.distance(b));
            CHECK_EQ(a.distance(b), doctest::Approx(5));

            CHECK_NOTHROW(a1.distance(b1));
            CHECK_EQ(a1.distance(b1), doctest::Approx(5.66));

            CHECK_NOTHROW(a2.distance(b2));
            CHECK_EQ(a2.distance(b2), doctest::Approx(7.64));

            CHECK_NOTHROW(a3.distance(b3));
            CHECK_EQ(a3.distance(b3), doctest::Approx(11.77));
        }

        SUBCASE("print") {
            CHECK_NOTHROW(a.print());
            CHECK_NOTHROW(b.print());
            CHECK_NOTHROW(a1.print());
            CHECK_NOTHROW(b1.print());
            CHECK_NOTHROW(a2.print());
            CHECK_NOTHROW(b2.print());
            CHECK_NOTHROW(a3.print());
            CHECK_NOTHROW(b3.print());
        }

        SUBCASE("moveTowards") {
            CHECK_NOTHROW(a.moveTowards(b));
            CHECK_NOTHROW(a1.moveTowards(b1));
            CHECK_NOTHROW(a2.moveTowards(b2));
            CHECK_NOTHROW(a3.moveTowards(b3));
        }
    }
}

TEST_SUITE("Character class") {
    TEST_CASE("Cowboy class") {
        SUBCASE("constructors") {
            CHECK_NOTHROW(Cowboy("John", Point(1, 2)));
            CHECK_NOTHROW(Cowboy("Mike", Point(-1, 3)));
            CHECK_NOTHROW(Cowboy("Sam", Point(0.5, -2.7)));
            CHECK_NOTHROW(Cowboy("Dave", Point(-3.9, -8.1)));
        }

        SUBCASE("functions") {
            Cowboy* john = new Cowboy("John", Point(1, 2));
            Cowboy* mike = new Cowboy("Mike", Point(-1, 3));
            Cowboy* sam = new Cowboy("Sam", Point(0.5, -2.7));
            Cowboy* dave = new Cowboy("Dave", Point(-3.9, -8.1));

            SUBCASE("isAlive") {
                CHECK_NOTHROW(john->isAlive());
                CHECK_EQ(john->isAlive(), true);

                CHECK_NOTHROW(mike->isAlive());
                CHECK_EQ(mike->isAlive(), true);

                CHECK_NOTHROW(sam->isAlive());
                CHECK_EQ(sam->isAlive(), true);

                CHECK_NOTHROW(dave->isAlive());
                CHECK_EQ(dave->isAlive(), true);
            }

            SUBCASE("hit") {
                CHECK_NOTHROW(john->hit(20));
                CHECK_NOTHROW(mike->hit(110));
                CHECK_THROWS(mike->hit(1));
                CHECK_NOTHROW(sam->hit(0));
                CHECK_THROWS(dave->hit(120));
            }

            SUBCASE("getName") {
                CHECK_EQ(john->getName(), "John");
                CHECK_EQ(mike->getName(), "Mike");
                CHECK_EQ(sam->getName(), "Sam");
                CHECK_EQ(dave->getName(), "Dave");
            }

            SUBCASE("getLocation") {
                CHECK_NOTHROW(john->getLocation());
                CHECK_NOTHROW(mike->getLocation());
                CHECK_NOTHROW(sam->getLocation());
                CHECK_NOTHROW(dave->getLocation());
            }

            SUBCASE("shoot") {
                CHECK_NOTHROW(john->shoot(mike));
                CHECK_NOTHROW(mike->shoot(john));
                CHECK_NOTHROW(sam->shoot(dave));
                CHECK_NOTHROW(dave->shoot(sam));

                CHECK_THROWS(john->shoot(john));
                CHECK_THROWS(mike->shoot(mike));
                CHECK_THROWS(sam->shoot(sam));
                CHECK_THROWS(dave->shoot(dave));
            }

            SUBCASE("hasBullets") {
                CHECK_NOTHROW(john->hasBullets());
                while (john->hasBullets()) {
                    john->shoot(mike);
                }
                CHECK_EQ(john->hasBullets(), false);

                CHECK_NOTHROW(sam->hasBullets());
                while (sam->hasBullets()) {
                    sam->shoot(dave);
                }
                CHECK_EQ(sam->hasBullets(), false);
            }

            SUBCASE("reload") {
                if (!john->hasBullets()) {
                    CHECK_NOTHROW(john->reload());
                }
                CHECK_EQ(john->hasBullets(), true);

                if (!mike->hasBullets()) {
                    CHECK_NOTHROW(mike->reload());
                }
                CHECK_EQ(mike->hasBullets(), true);

                if (!sam->hasBullets()) {
                    CHECK_NOTHROW(sam->reload());
                }
                CHECK_EQ(sam->hasBullets(), true);

                if (!dave->hasBullets()) {
                    CHECK_NOTHROW(dave->reload());
                }
                CHECK_EQ(dave->hasBullets(), true);
            }

            SUBCASE("print") {
                CHECK_NOTHROW(john->print());
                CHECK_NOTHROW(mike->print());
                CHECK_NOTHROW(sam->print());
                CHECK_NOTHROW(dave->print());
            }
        }
    }

    TEST_CASE("Ninja class") {
        SUBCASE("constructors") {
            CHECK_NOTHROW(Ninja("Naruto", Point(1, 2), 100, 80));
            CHECK_NOTHROW(Ninja("Sasuke", Point(-1, 3), 0, 100));
            CHECK_NOTHROW(Ninja("Kakashi", Point(0.5, -2.7), 150, 0));
            CHECK_NOTHROW(Ninja("Itachi", Point(-3.9, -8.1), 0, 0));
        }

        SUBCASE("functions") {
            Ninja* naruto = new Ninja("Naruto", Point(1, 2), 150, 20);
            Ninja* sasuke = new Ninja("Sasuke", Point(-1, 3), 100, 40);
            Ninja* kakashi = new Ninja("Kakashi", Point(0.5, -2.7), 50, 0);
            Ninja* itachi = new Ninja("Itachi", Point(-3.9, -8.1), 0, 100);

            SUBCASE("isAlive") {
                CHECK_NOTHROW(naruto->isAlive());
                CHECK_EQ(naruto->isAlive(), true);

                CHECK_NOTHROW(sasuke->isAlive());
                CHECK_EQ(sasuke->isAlive(), true);

                CHECK_NOTHROW(kakashi->isAlive());
                CHECK_EQ(kakashi->isAlive(), true);

                CHECK_NOTHROW(itachi->isAlive());
                CHECK_EQ(itachi->isAlive(), true);
            }

            SUBCASE("getName") {
                CHECK_EQ(naruto->getName(), "Naruto");
                CHECK_EQ(sasuke->getName(), "Sasuke");
                CHECK_EQ(kakashi->getName(), "Kakashi");
                CHECK_EQ(itachi->getName(), "Itachi");
            }

            SUBCASE("getLocation") {
                CHECK_NOTHROW(naruto->getLocation());
                CHECK_NOTHROW(sasuke->getLocation());
                CHECK_NOTHROW(kakashi->getLocation());
                CHECK_NOTHROW(itachi->getLocation());
            }

            SUBCASE("move") {
                CHECK_NOTHROW(naruto->move(sasuke));
                CHECK_NOTHROW(sasuke->move(kakashi));
                CHECK_NOTHROW(kakashi->move(itachi));
                CHECK_NOTHROW(itachi->move(naruto));
            }

            SUBCASE("slash") {
                CHECK_NOTHROW(naruto->slash(sasuke));
                CHECK_NOTHROW(sasuke->slash(kakashi));
                CHECK_NOTHROW(kakashi->slash(itachi));
                CHECK_NOTHROW(itachi->slash(naruto));
            }

            SUBCASE("print") {
                CHECK_NOTHROW(naruto->print());
                CHECK_NOTHROW(sasuke->print());
                CHECK_NOTHROW(kakashi->print());
                CHECK_NOTHROW(itachi->print());
            }
        }
    }

    TEST_CASE("OldNinja class") {
        OldNinja* naruto = new OldNinja("Naruto", Point(1, 2));

        SUBCASE("constructors") {
            CHECK_NOTHROW(OldNinja("Naruto", Point(1, 2)));
            CHECK_NOTHROW(OldNinja("Sasuke", Point(-1, 3)));
            CHECK_NOTHROW(OldNinja("Kakashi", Point(0.5, -2.7)));
            CHECK_NOTHROW(OldNinja("Itachi", Point(-3.9, -8.1)));
        }

        SUBCASE("hit") {
            CHECK_NOTHROW(naruto->hit(10));
            CHECK_NOTHROW(naruto->hit(140));
            CHECK_THROWS(naruto->hit(1));
        }
    }

    TEST_CASE("YoungNinja class") {
        YoungNinja* naruto = new YoungNinja("Naruto", Point(1, 2));

        SUBCASE("constructors") {
            CHECK_NOTHROW(YoungNinja("Naruto", Point(1, 2)));
            CHECK_NOTHROW(YoungNinja("Sasuke", Point(-1, 3)));
            CHECK_NOTHROW(YoungNinja("Kakashi", Point(0.5, -2.7)));
            CHECK_NOTHROW(YoungNinja("Itachi", Point(-3.9, -8.1)));
        }

        SUBCASE("hit") {
            CHECK_NOTHROW(naruto->hit(10));
            CHECK_NOTHROW(naruto->hit(90));
            CHECK_THROWS(naruto->hit(1));
        }
    }

    TEST_CASE("TrainedNinja class") {
        TrainedNinja* naruto = new TrainedNinja("Naruto", Point(1, 2));

        SUBCASE("constructors") {
            CHECK_NOTHROW(TrainedNinja("Naruto", Point(1, 2)));
            CHECK_NOTHROW(TrainedNinja("Sasuke", Point(-1, 3)));
            CHECK_NOTHROW(TrainedNinja("Kakashi", Point(0.5, -2.7)));
            CHECK_NOTHROW(TrainedNinja("Itachi", Point(-3.9, -8.1)));
        }

        SUBCASE("hit") {
            CHECK_NOTHROW(naruto->hit(10));
            CHECK_NOTHROW(naruto->hit(110));
            CHECK_THROWS(naruto->hit(1));
        }
    }
}

TEST_SUITE("Teams class") {
    Cowboy* john = new Cowboy("John", Point(1, 2));
    OldNinja* naruto = new OldNinja("Naruto", Point(1, 2));
    YoungNinja* sasuke = new YoungNinja("Sasuke", Point(1, 2));
    TrainedNinja* kakashi = new TrainedNinja("Kakashi", Point(1, 2));

    TEST_CASE("Team class") {
        SUBCASE("constructors") {
            CHECK_NOTHROW(Team team1(john));
            CHECK_NOTHROW(Team team2(naruto));
            CHECK_NOTHROW(Team team3(sasuke));
            CHECK_NOTHROW(Team team4(kakashi));
        }

        SUBCASE("functions") {
            Team* team_A = new Team(john);
            Team* team_B = new Team(naruto);

            SUBCASE("add") {
                CHECK_NOTHROW(team_A->add(sasuke));
                CHECK_NOTHROW(team_B->add(kakashi));
            }

            SUBCASE("attack") {
                CHECK_NOTHROW(team_A->attack(team_B));
                CHECK_NOTHROW(team_B->attack(team_A));
            }

            SUBCASE("stillAlive") {
                CHECK_NOTHROW(team_A->stillAlive());
                CHECK_NOTHROW(team_B->stillAlive());
            }

            SUBCASE("print") {
                CHECK_NOTHROW(team_A->print());
                CHECK_NOTHROW(team_B->print());
            }
        }
    }

    TEST_CASE("Team2 class") {
        SUBCASE("constructors") {
            CHECK_NOTHROW(Team2 team5(john));
            CHECK_NOTHROW(Team2 team6(naruto));
            CHECK_NOTHROW(Team2 team7(sasuke));
            CHECK_NOTHROW(Team2 team8(kakashi));
        }

        SUBCASE("functions") {
            Team2* team_A = new Team2(john);
            Team2* team_B = new Team2(naruto);

            SUBCASE("add") {
                CHECK_NOTHROW(team_A->add(sasuke));
                CHECK_NOTHROW(team_B->add(kakashi));
            }

            SUBCASE("attack") {
                CHECK_NOTHROW(team_A->attack(team_B));
                CHECK_NOTHROW(team_B->attack(team_A));
            }

            SUBCASE("stillAlive") {
                CHECK_NOTHROW(team_A->stillAlive());
                CHECK_NOTHROW(team_B->stillAlive());
            }

            SUBCASE("print") {
                CHECK_NOTHROW(team_A->print());
                CHECK_NOTHROW(team_B->print());
            }
        }
    }

    TEST_CASE("SmartTeam class") {
        SUBCASE("constructors") {
            CHECK_NOTHROW(SmartTeam team9(john));
            CHECK_NOTHROW(SmartTeam team10(naruto));
            CHECK_NOTHROW(SmartTeam team11(sasuke));
            CHECK_NOTHROW(SmartTeam team12(kakashi));
        }

        SUBCASE("functions") {
            SmartTeam* team_A = new SmartTeam(john);
            SmartTeam* team_B = new SmartTeam(naruto);

            SUBCASE("add") {
                CHECK_NOTHROW(team_A->add(sasuke));
                CHECK_NOTHROW(team_B->add(kakashi));
            }

            SUBCASE("attack") {
                CHECK_NOTHROW(team_A->attack(team_B));
                CHECK_NOTHROW(team_B->attack(team_A));
            }

            SUBCASE("stillAlive") {
                CHECK_NOTHROW(team_A->stillAlive());
                CHECK_NOTHROW(team_B->stillAlive());
            }

            SUBCASE("print") {
                CHECK_NOTHROW(team_A->print());
                CHECK_NOTHROW(team_B->print());
            }

            SUBCASE("getEnemy") {
                CHECK_NOTHROW(team_A->getEnemy(team_B));
                CHECK_NOTHROW(team_B->getEnemy(team_A));
            }
        }
    }
}

TEST_SUITE("game") {
    TEST_CASE("classic game") {
        Point a(1, 2);
        Point b(3, 4);
        Cowboy* john = new Cowboy("John", a);
        OldNinja* naruto = new OldNinja("Naruto", b);

        Team team_A(john);
        team_A.add(new YoungNinja("Yogi", Point(5, 6)));

        Team team_B(naruto);
        team_B.add(new OldNinja("Hikari", Point(7, 8)));

        while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0) {
            CHECK_NOTHROW(team_A.attack(&team_B));
            CHECK_NOTHROW(team_B.attack(&team_A));
        }

        CHECK(team_A.stillAlive() > 0);
        CHECK(team_B.stillAlive() == 0);
    }

    TEST_CASE("different type of teams game") {
        SUBCASE("team vs team2") {
            Point a(1, 2);
            Point b(3, 4);
            Cowboy* john = new Cowboy("John", a);
            OldNinja* naruto = new OldNinja("Naruto", b);

            Team2 team_A(john);
            team_A.add(new YoungNinja("Yogi", Point(5, 6)));

            Team team_B(naruto);
            team_B.add(new OldNinja("Hikari", Point(7, 8)));

            while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0) {
                CHECK_NOTHROW(team_A.attack(&team_B));
                CHECK_NOTHROW(team_B.attack(&team_A));
            }

            CHECK(team_A.stillAlive() > 0);
            CHECK(team_B.stillAlive() == 0);
        }

        SUBCASE("team vs smartTeam") {
            Point a(1, 2);
            Point b(3, 4);
            Cowboy* john = new Cowboy("John", a);
            OldNinja* naruto = new OldNinja("Naruto", b);

            SmartTeam team_A(john);
            team_A.add(new YoungNinja("Yogi", Point(5, 6)));

            Team team_B(naruto);
            team_B.add(new OldNinja("Hikari", Point(7, 8)));

            while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0) {
                CHECK_NOTHROW(team_A.attack(&team_B));
                CHECK_NOTHROW(team_B.attack(&team_A));
            }

            CHECK(team_A.stillAlive() > 0);
            CHECK(team_B.stillAlive() == 0);
        }

        SUBCASE("team2 vs smartTeam") {
            Point a(1, 2);
            Point b(3, 4);
            Cowboy* john = new Cowboy("John", a);
            OldNinja* naruto = new OldNinja("Naruto", b);

            SmartTeam team_A(john);
            team_A.add(new YoungNinja("Yogi", Point(5, 6)));

            Team2 team_B(naruto);
            team_B.add(new OldNinja("Hikari", Point(7, 8)));

            while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0) {
                CHECK_NOTHROW(team_A.attack(&team_B));
                CHECK_NOTHROW(team_B.attack(&team_A));
            }

            CHECK(team_A.stillAlive() > 0);
            CHECK(team_B.stillAlive() == 0);
        }
    }
}
