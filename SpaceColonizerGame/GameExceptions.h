/*
James Felts 2015
*/
//this is a convenient header that allows including all the exception headers that the game has with just one include
#ifndef GAMEEXCEPTIONS_H
#define GAMEEXCEPTIONS_H
#ifdef _MSC_VER
#pragma warning(disable: 4505 4514 4668 4820 4710 4711)
#endif
//root of exception tree
#include "Utils/Exceptions/game_exception.h"

#include "Utils/Exceptions/game_logic_error.h"

#include "Utils/Exceptions/game_domain_error.h"
#include "Utils/Exceptions/game_invalid_argument.h"
#include "Utils/Exceptions/game_length_error.h"
#include "Utils/Exceptions/game_out_of_range.h"

#include "Utils/Exceptions/game_runtime_error.h"

#include "Utils/Exceptions/game_range_error.h"

#endif
