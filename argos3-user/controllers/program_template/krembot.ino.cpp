/*******************************************************************************
* Copyright (c) 2019, Elhay Rauper.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* * Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
*
* * Redistributions in binary form must reproduce the above copyright notice,
*   this list of conditions and the following disclaimer in the documentation
*   and/or other materials provided with the distribution.
*
* * Neither the name of Elhay Rauper nor the names of its
*   contributors may be used to endorse or promote products derived from
*   this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/


/*
 * This file simulates the .ino file of the krembot.
 * The original structure of this file must be maintained
 * for the simulator to work correctly.
 * Don't create Krembot instance, it is created automatically.
 * Copy and past real robot setup() and loop() code into the functions below
 */

#include <Krembot/controller/krembot_controller.h>

/*
 * todo: Your #include statements goes here
 */

//DO NOT EDIT THIS MACRO
KREMBOT_CONTROLLER_HEADER

////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////

/*
 * todo: Your global variables goes here
 */


void setup() {
    krembot.setup();

    /*
     * todo: Your setup code goes here
     */
}

void loop() {
    krembot.loop();

    /*
     * todo: Your loop code goes here
     */
}


////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////

//DO NOT EDIT THESE MACROS
KREMBOT_CONTROLLER_FOOTER
///* \
// * This statement notifies ARGoS of the existence of the controller. \
// * It binds the class passed as first argument to the string passed as \
// * second argument. \
// * The string is then usable in the configuration file to refer to this \
// * controller. \
// * When ARGoS reads that string in the configuration file, it knows which \
// * controller class to instantiate. \
// * See also the configuration files for an example of how this is used. \
// */
REGISTER_CONTROLLER(MyController, KREMBOT_PROGRAM_NAME)



