#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "sim.hpp"


SCENARIO( "States can be added", "[added]" ) {

	GIVEN( "a new sim" ) {

		Sim sim = Sim();

		REQUIRE( sim.getInitialState() == "" );
		REQUIRE( sim.getCurrentState() == "" );
		REQUIRE( sim.getNumStates() == 0 );

		WHEN( "add one state" ) {
			sim.addState("Home");
			THEN( "have one state" ) {
				REQUIRE( sim.getNumStates() == 1 );
				REQUIRE( sim.isState("Home") == true );
				REQUIRE( sim.isState("School") == false );
			}
		}

		WHEN( "add two states" ) {
			sim.addState("Home");
			sim.addState("School");
			THEN( "have two states" ) {
				REQUIRE( sim.getNumStates() == 2 );
				REQUIRE( sim.isState("Home") == true );
				REQUIRE( sim.isState("School") == true );
			}
		}

		WHEN( "add three states" ) {
			sim.addState("Home");
			sim.addState("School");
			sim.addState("Market");
			THEN( "have three states" ) {
				REQUIRE( sim.getNumStates() == 3 );
				REQUIRE( sim.isState("Home") == true );
				REQUIRE( sim.isState("School") == true );
				REQUIRE( sim.isState("Market") == true );
			}
		}

	}

}

SCENARIO( "The initial state can be set", "[initialState]" ) {

	GIVEN( "a new sim" ) {

		Sim sim = Sim();

		sim.addState("Home");
		sim.addState("School");
		sim.addState("Market");

		WHEN( "set a valid initial state" ) {
			sim.setInitialState("Home");
			THEN( "the initial state is set" ) {
				REQUIRE( sim.getInitialState() == "Home" );
				REQUIRE( sim.getInitialState() != "School" );
				REQUIRE( sim.getInitialState() != "Market" );
				REQUIRE( sim.getInitialState() != "Laundry" );
			}
			THEN( "the current state is set" ) {
				REQUIRE( sim.getCurrentState() == "Home" );
				REQUIRE( sim.getCurrentState() != "School" );
				REQUIRE( sim.getCurrentState() != "Market" );
				REQUIRE( sim.getCurrentState() != "Laundry" );
			}
		}

		WHEN( "set an invalid initial state" ) {
			sim.setInitialState("Laundry");
			THEN( "the initial state is not set" ) {
				REQUIRE( sim.getInitialState() == "" );
				REQUIRE( sim.getInitialState() != "Home" );
				REQUIRE( sim.getInitialState() != "School" );
				REQUIRE( sim.getInitialState() != "Market" );
				REQUIRE( sim.getInitialState() != "Laundry" );
			}
			THEN( "the current state is not set" ) {
				REQUIRE( sim.getCurrentState() == "" );
				REQUIRE( sim.getCurrentState() != "Home" );
				REQUIRE( sim.getCurrentState() != "School" );
				REQUIRE( sim.getCurrentState() != "Market" );
				REQUIRE( sim.getCurrentState() != "Laundry" );
			}
		}

	}

}


SCENARIO( "States can be linked", "[linked]" ) {

	GIVEN( "add Home, School, and Market" ) {

		Sim sim = Sim();

		sim.addState("Home");
		sim.addState("School");
		sim.addState("Market");

		WHEN( "link Home to School and School to Market" ) {

			sim.linkStates("Home","School");
			sim.linkStates("School","Market");

			THEN( "home linked to school" ) {
				REQUIRE( sim.areLinkedStates("Home","School") == true );
			}
			THEN( "school linked to market" ) {
				REQUIRE( sim.areLinkedStates("School","Market") == true );
			}
			THEN( "home not linked to market" ) {
				REQUIRE( sim.areLinkedStates("Home","Market") == false );
			}
			THEN( "home not linked to home" ) {
				REQUIRE( sim.areLinkedStates("Home","Home") == false );
			}
			THEN( "school not linked to home" ) {
				REQUIRE( sim.areLinkedStates("School","Home") == false );
			}

		}

	}

}



SCENARIO( "States can be traversed", "[traversed]" ) {

	GIVEN( "add Home, School, and Market" ) {

		Sim sim = Sim();

		sim.addState("Home");
		sim.addState("School");
		sim.addState("Market");
		sim.addState("Laundry");

		sim.linkStates("Home","School");
		sim.linkStates("School","Home");
		sim.linkStates("School","Market");
		sim.linkStates("Market","School");
		sim.linkStates("Market","Home");
		sim.linkStates("Home","Market");
		sim.linkStates("Market","Laundry");
		sim.linkStates("Laundry","Market");

		sim.setInitialState("Home");

		WHEN( "to School to Market" ) {

			sim.move("School");
			sim.move("Market");

			THEN( "at the Market" ) {
				REQUIRE( sim.getCurrentState() == "Market" );
			}

		}

		WHEN( "to School to Market to Laundry" ) {

			sim.move("School");
			sim.move("Market");
			sim.move("Laundry");

			THEN( "at the Laundry" ) {
				REQUIRE( sim.getCurrentState() == "Laundry" );
			}

		}

		WHEN( "to Market" ) {

			sim.move("Market");

			THEN( "at the Market" ) {
				REQUIRE( sim.getCurrentState() == "Market" );
			}

		}

		WHEN( "to Market to Laundry" ) {

			sim.move("Market");
			sim.move("Laundry");

			THEN( "at the Laundry" ) {
				REQUIRE( sim.getCurrentState() == "Laundry" );
			}

		}

		WHEN( "to Market to Home" ) {

			sim.move("Market");
			sim.move("Home");

			THEN( "at the Home" ) {
				REQUIRE( sim.getCurrentState() == "Home" );
			}

		}





	}

}

