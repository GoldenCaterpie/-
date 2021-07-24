//std
.equ MSG_OBTAIN, 0x0
.equ MSG_FIND, 0x1
.equ MSG_FACE, 0x2
.equ MSG_SIGN, 0x3
.equ MSG_KEEPOPEN, 0x4
.equ MSG_YESNO, 0x5
.equ MSG_NORMAL, 0x6
.equ MSG_POKENAV, 0xA

//applymovement
.equ MOVE_PLAYER, 0xFF
.equ MOVE_CAMERA, 0x7F

//vars
.equ LASTRESULT, 0x800D
.equ LASTTALKED, 0x800F

//Compare values
.equ lessthan, 0x0 //A is less than B
.equ equal, 0x1 //A is equal to B
.equ greaterthan, 0x2 //A is more than B
.equ lessorequal, 0x3 //A is less than or equal to B
.equ greaterorequal, 0x4 //A is greater than or equal to B
.equ notequal, 0x5 //A is not equal to B

//azuril13's if command becuase it's nice
.equ _goto, 0x06
.equ _call, 0x07

.macro if, condition, goto_or_call, script
.byte \goto_or_call
.byte \condition
.4byte \script
.endm

.macro msgbox, msgbox_pointer, msgbox_type
.byte 0xF
.byte 0x0
.4byte \msgbox_pointer
.byte 0x9
.byte \msgbox_type
.endm

.macro giveitem, giveitem_item, giveitem_amount, giveitem_msgtype
.byte 0x1A
.2byte 0x8000
.2byte \giveitem_item
.byte 0x1A
.2byte 0x8001
.2byte \giveitem_amount
.byte 0x9
.byte \giveitem_msgtype
.endm

.macro giveitem2, giveitem2_item, giveitem2_amount, giveitem2_song
.byte 0x1A
.2byte 0x8000
.2byte \giveitem2_item
.byte 0x1A
.2byte 0x8001
.2byte \giveitem2_amount
.byte 0x1A
.2byte 0x8002
.2byte \giveitem2_song
.byte 0x9
.byte 0x9
.endm

.macro giveitem3, giveitem3_decoration
.byte 0x1A
.4byte 0x8000
.2byte \giveitem3_decoration
.byte 0x9
.byte 0x7
.endm

.macro wildbattle, wildbattle_species, wildbattle_level, wildbattle_item
.byte 0xB6
.2byte \wildbattle_species
.byte \wildbattle_level
.2byte \wildbattle_item
.byte 0xB7
.endm

.macro registernav, registernav_trainer
.byte 0x1A
.2byte 0x8000
.2byte \registernav_trainer
.byte 0x9
.byte 0x8
.endm

//Commands
.macro nop
.byte 0x0
.endm

.macro nop1
.byte 0x1
.endm

.macro end
.byte 0x2
.endm

.macro return
.byte 0x3
.endm

.macro call, call_destination
.byte 0x4
.4byte \call_destination
.endm

.macro goto, goto_destination
.byte 0x5
.4byte \goto_destination
.endm

.macro if1, if1_condition, if1_goto_destination
.byte 0x6
.byte \if1_condition
.4byte \if1_goto_destination
.endm

.macro if2, if2_condition, if2_call_destination
.byte 0x7
.byte \if2_condition
.4byte \if2_call_destination
.endm

.macro gotostd, gotostd_param1
.byte 0x8
.byte \gotostd_param1
.endm

.macro callstd, callstd_param1
.byte 0x9
.byte \callstd_param1
.endm

.macro gotostdif, gotostdif_cond, gotostdif_param1
.byte 0xA
.byte \gotostdif_cond
.byte \gotostdif_param1
.endm

.macro callstdif, callstdif_cond, callstdif_param1
.byte 0xB
.byte \callstdif_cond
.byte \callstdif_param1
.endm

//jumpram's documentation may not be complete
.macro jumpram
.byte 0xC
.endm

.macro killscript
.byte 0xD
.endm

.macro setbyte, setbyte_value
.byte 0xE
.byte \setbyte_value
.endm

.macro loadpointer, loadpointer_bank, loadpointer_pointer
.byte 0xF
.byte \loadpointer_bank
.4byte \loadpointer_pointer
.endm

.macro setbyte2, setbyte2_bank, setbyte2_value
.byte 0x10
.byte \setbyte2_bank
.byte \setbyte2_value
.endm

.macro writebytetooffset, wbto_byte, wbto_pointer
.byte 0x11
.byte \wbto_byte
.4byte \wbto_pointer
.endm

.macro loadbytefrompointer, lbfp_bank_dest, lbfp_pointer
.byte 0x12
.byte \lbfp_bank_dest
.4byte \lbfp_pointer
.endm

.macro setfarbyte, setfarbyte_bank, setfarbyte_pointer
.byte 0x13
.byte \setfarbyte_bank
.4byte \setfarbyte_pointer
.endm

.macro copyscriptbanks, copyscriptbanks_bank_destination, copyscriptbanks_bank_source
.byte 0x14
.byte \copyscriptbanks_bank_destination
.byte \copyscriptbanks_bank_source
.endm

.macro copybyte, copybyte_dest, copybyte_source
.byte 0x15
.4byte \copybyte_dest
.4byte \copybyte_source
.endm

.macro setvar, setvar_var, setvar_value
.byte 0x16
.2byte \setvar_var
.2byte \setvar_value
.endm

.macro addvar, addvar_var, addvar_value
.byte 0x17
.2byte \addvar_var
.2byte \addvar_value
.endm

.macro subvar, subvar_var, subvar_value
.byte 0x18
.2byte \subvar_var
.2byte \subvar_value
.endm

.macro copyvar, copyvar_destination, copyvar_source
.byte 0x19
.2byte \copyvar_destination
.2byte \copyvar_source
.endm

.macro copyvarifnotzero, copyvarifnotzero_var, copyvarifnotzero_source
.byte 0x1A
.2byte \copyvarifnotzero_var
.2byte \copyvarifnotzero_source
.endm

.macro comparebanks, comparebanks_a, comparebanks_b
.byte 0x1B
.byte \comparebanks_a
.byte \comparebanks_b
.endm

.macro comparebanktobyte, comparebanktobyte_bank, comparebanktobyte_byte
.byte 0x1C
.byte \comparebanktobyte_bank
.byte \comparebanktobyte_byte
.endm

.macro comparebanktofarbyte, comparebbanktofarbyte_bank, comparebanktofarbyte_pointer
.byte 0x1D
.byte \comparebanktofarbyte_bank
.4byte \comparebanktofarbyte_pointer
.endm

.macro comparefarbytetobank, comparefarbytetobank_pointer, comparefarbytetobank_bank
.byte 0x1E
.4byte \comparefarbytetobank_pointer
.byte \comparefarbytetobank_bank
.endm

.macro comparefarbytetobyte, comparefarbytetobyte_pointer, comparefarbytetobyte_byte
.byte 0x1F
.4byte \comparefarbytetobyte_pointer
.byte \comparefarbytetobyte_byte
.endm

.macro comparefarbytes, comparefarbytes_param1, comparefarbytes_param2
.byte 0x20
.4byte \comparefarbytes_param1
.4byte \comparefarbytes_param2
.endm

.macro compare, compare_var, compare_value
.byte 0x21
.2byte \compare_var
.2byte \compare_value
.endm

.macro comparevars, comparevars_var1, comparevars_var2
.byte 0x22
.2byte \comparevars_var1
.2byte \comparevars_var2
.endm

.macro callasm, callasm_pointer
.byte 0x23
.4byte \callasm_pointer
.endm

.macro cmd24, cmd24_pointer
.byte 0x24
.4byte \cmd24_pointer
.endm

.macro special, special_param
.byte 0x25
.2byte \special_param
.endm

.macro special2, special2_outputvar, special2_function
.byte 0x26
.2byte \special2_outputvar
.2byte \special2_function
.endm

.macro waitstate
.byte 0x27
.endm

.macro pause, pause_time
.byte 0x28
.2byte \pause_time
.endm

.macro setflag, setflag_flag
.byte 0x29
.2byte \setflag_flag
.endm

.macro clearflag, clearflag_flag
.byte 0x2A
.2byte \clearflag_flag
.endm

.macro checkflag, checkflag_flag
.byte 0x2B
.2byte \checkflag_flag
.endm

//nop in FR
.macro cmd2C
.byte 0x2C
.endm

//nop in FR, no other info right now.
.macro checkdailyflags
.byte 0x2D
.endm

.macro resetvars, gettime
.byte 0x2E
.endm

.macro sound, sound_id
.byte 0x2F
.2byte sound_id
.endm

.macro checksound
.byte 0x30
.endm

.macro fanfare, fanfare_id
.byte 0x31
.2byte \fanfare_id
.endm

.macro waitfanfare
.byte 0x32
.endm

.macro playsong, playsong_songid, playsong_unknown
.byte 0x33
.2byte \playsong_songid
.byte \playsong_unknown
.endm

.macro playsong2, playsong2_song
.byte 0x34
.2byte \playsong2_song
.endm

.macro fadedefault
.byte 0x35
.endm

.macro fadesong, fadesong_song
.byte 0x36
.2byte \fadesong_song
.endm

.macro fadeout, fadeout_speed
.byte 0x37
.byte \fadeout_speed
.endm

.macro fadein, fadein_speed
.byte 0x38
.byte \fadein_speed
.endm

.macro warp, warp_bank, warp_map, warp_warp, warp_x_axis, warp_y_axis
.byte 0x39
.byte \warp_bank
.byte \warp_map
.byte \warp_warp
.2byte \warp_x_axis
.2byte \warp_y_axis
.endm

.macro warpmuted, warpmuted_bank, warpmuted_map, warpmuted_warp, warpmuted_x_axis, warpmuted_y_axis
.byte 0x3A
.byte \warpmuted_bank
.byte \warpmuted_map
.byte \warpmuted_warp
.2byte \warpmuted_x_axis
.2byte \warpmuted_y_axis
.endm

.macro warpwalk, warpwalk_bank, warpwalk_map, warpwalk_warp, warpwalk_x_axis, warpwalk_y_axis
.byte 0x3B
.byte \warpwalk_bank
.byte \warpwalk_map
.byte \warpwalk_warp
.2byte \warpwalk_x_axis
.2byte \warpwalk_y_axis
.endm

.macro warphole, warphole_bank, warphole_map
.byte 0x3C
.byte \warphole_bank
.byte \warphole_map
.endm

.macro warpteleport, warpteleport_bank, warpteleport_map, warpteleport_warp, warpteleport_x_axis, warpteleport_y_axis
.byte 0x3D
.byte \warpteleport_bank
.byte \warpteleport_map
.byte \warpteleport_warp
.2byte \warpteleport_x_axis
.2byte \warpteleport_y_axis
.endm

.macro warp3, warp3_bank, warp3_map, warp3_warp, warp3_x_axis, warp3_y_axis
.byte 0x3E
.byte \warp3_bank
.byte \warp3_map
.byte \warp3_warp
.2byte \warp3_x_axis
.2byte \warp3_y_axis
.endm

.macro setwarpplace, setwarpplace_bank, setwarpplace_map, setwarpplace_warp, setwarpplace_x_axis, setwarpplace_y_axis
.byte 0x3F
.byte \setwarpplace_bank
.byte \setwarpplace_map
.byte \setwarpplace_warp
.2byte \setwarpplace_x_axis
.2byte \setwarpplace_y_axis
.endm

.macro warp4, warp4_bank, warp4_map, warp4_warp, warp4_x_axis, warp4_y_axis
.byte 0x40
.byte \warp4_bank
.byte \warp4_map
.byte \warp4_warp
.2byte \warp4_x_axis
.2byte \warp4_y_axis
.endm

.macro warp5, warp5_bank, warp5_map, warp5_warp, warp5_x_axis, warp5_y_axis
.byte 0x41
.byte \warp5_bank
.byte \warp5_map
.byte \warp5_warp
.2byte \warp5_x_axis
.2byte \warp5_y_axis
.endm

.macro getplayerpos, getplayerpos_x_var, getplayerpos_y_var
.byte 0x42
.2byte \getplayerpos_x_var
.2byte \getplayerpos_y_var
.endm

.macro countpokemon
.byte 0x43
.endm

.macro additem, additem_index, additem_quantity
.byte 0x44
.2byte \additem_index
.2byte \additem_quantity
.endm

.macro removeitem, removeitem_index, removeitem_quantity
.byte 0x45
.2byte \removeitem_index
.2byte \removeitem_quantity
.endm

.macro checkitemroom, checkitemroom_index, checkitemroom_quantity
.byte 0x46
.2byte \checkitemroom_index
.2byte \checkitemroom_quantity
.endm

.macro checkitem, checkitem_index, checkitem_quantity
.byte 0x47
.2byte \checkitem_index
.2byte \checkitem_quantity
.endm

.macro checkitemtype, checkitemtype_index
.byte 0x48
.2byte \checkitemtype_index
.endm

.macro addpcitem, addpcitem_index, addpcitem_quantity
.byte 0x49
.2byte \addpcitem_index
.2byte \addpcitem_quantity
.endm

.macro checkpcitem, checkpcitem_index, checkpcitem_quantity
.byte 0x4A
.2byte \checkpcitem_index
.2byte \checkpcitem_quantity
.endm

.macro adddecoration, adddecoration_decoration
.byte 0x4B
.2byte \adddecoration_decoration
.endm

.macro removedecoration, removedecoration_decoration
.byte 0x4C
.2byte \removedecoration_decoration
.endm

.macro testdecoration, testdecoration_decoration
.byte 0x4D
.2byte \testdecoration_decoration
.endm

.macro checkdecoration, checkdecoration_decoration
.byte 0x4E
.2byte \checkdecoration_decoration
.endm

.macro applymovement, applymovement_person_id, applymovement_pointer
.byte 0x4F
.2byte \applymovement_person_id
.4byte \applymovement_pointer
.endm

.macro applymovementpos, applymovementpos_var, applymovementpos_pointer
.byte 0x50
.2byte \applymovementpos_var
.4byte \applymovementpos_pointer
.endm

.macro waitmovement, waitmovement_index
.byte 0x51
.2byte \waitmovement_index
.endm

.macro waitmovementpos, waitmovementpos_index, waitmovementpos_x, waitmovementpos_y
.byte 0x52
.2byte \waitmovementpos_index
.byte \waitmovementpos_x
.byte \waitmovementpos_y
.endm

.macro hidesprite, hidesprite_param
.byte 0x53
.2byte \hidesprite_param
.endm

.macro hidespritepos, hidespritepos_index, hidespritepos_x, hidespritepos_y
.byte 0x54
.2byte \hidespritepos_index
.byte \hidespritepos_x
.byte \hidespritepos_y
.endm

.macro showsprite, showsprite_id
.byte 0x55
.2byte \showsprite_id
.endm

.macro movesprite, movesprite_person, movesprite_x, movesprite_y
.byte 0x57
.2byte \movesprite_person
.2byte \movesprite_x
.2byte \movesprite_y
.endm

.macro faceplayer
.byte 0x5A
.endm

.macro trainerbattle0, trainerbattle0_index, trainerbattle0_intro, trainerbattle0_loss
.byte 0x5C
.byte 0x0
.2byte \trainerbattle0_index
.2byte 0
.4byte \trainerbattle0_intro
.4byte \trainerbattle0_loss
.endm

.macro trainerbattle1, trainerbattle1_index, trainerbattle1_intro, trainerbattle1_loss, trainerbattle1_extra
.byte 0x5C
.byte 0x1
.2byte \trainerbattle1_index
.2byte 0
.4byte \trainerbattle1_intro
.4byte \trainerbattle1_loss
.4byte \trainerbattle1_extra
.endm

.macro trainerbattle2, trainerbattle2_index, trainerbattle2_intro, trainerbattle2_loss, trainerbattle2_extra
.byte 0x5C
.byte 0x2
.2byte \trainerbattle2_index
.2byte 0
.4byte \trainerbattle2_intro
.4byte \trainerbattle2_loss
.4byte \trainerbattle2_extra
.endm

.macro trainerbattle3, trainerbattle3_index, trainerbattle3_intro
.byte 0x5C
.byte 0x3
.2byte \trainerbattle3_index
.2byte 0
.4byte \trainerbattle3_intro
.endm

.macro trainerbattle4, trainerbattle4_index, trainerbattle4_intro, trainerbattle4_loss, trainerbattle4_extra
.byte 0x5C
.byte 0x4
.2byte \trainerbattle4_index
.2byte 0
.4byte \trainerbattle4_intro
.4byte \trainerbattle4_loss
.4byte \trainerbattle4_extra
.endm

.macro trainerbattle5, trainerbattle5_index, trainerbattle5_intro, trainerbattle5_loss
.byte 0x5C
.byte 0x5
.2byte \trainerbattle5_index
.2byte 0
.4byte \trainerbattle5_intro
.4byte \trainerbattle5_loss
.endm

.macro trainerbattle6, trainerbattle6_index, trainerbattle6_intro, trainerbattle6_loss, trainerbattle6_extra, trainerbattle6_extra2
.byte 0x5C
.byte 0x6
.2byte \trainerbattle6_index
.2byte 0
.4byte \trainerbattle6_intro
.4byte \trainerbattle6_loss
.4byte \trainerbattle6_extra
.4byte \trainerbattle6_extra2
.endm

.macro trainerbattle7, trainerbattle7_index, trainerbattle7_intro, trainerbattle7_loss, trainerbattle7_extra
.byte 0x5C
.byte 0x7
.2byte \trainerbattle7_index
.2byte 0
.4byte \trainerbattle7_intro
.4byte \trainerbattle7_loss
.4byte \trainerbattle7_extra
.endm

.macro trainerbattle8, trainerbattle8_index, trainerbattle8_intro, trainerbattle8_loss, trainerbattle8_extra, trainerbattle8_extra2
.byte 0x5C
.byte 0x8
.2byte \trainerbattle8_index
.2byte 0
.4byte \trainerbattle8_intro
.4byte \trainerbattle8_loss
.4byte \trainerbattle8_extra
.4byte \trainerbattle8_extra2
.endm

.macro trainerbattle9, trainerbattle9_index, trainerbattle9_intro, trainerbattle9_loss
.byte 0x5C
.byte 0x9
.2byte \trainerbattle9_index
.2byte 0
.4byte \trainerbattle9_intro
.4byte \trainerbattle9_loss
.endm

.macro repeattrainerbattle
.byte 0x5D
.endm

.macro endtrainerbattle
.byte 0x5E
.endm

.macro endtrainerbattle2
.byte 0x5F
.endm

.macro checktrainerflag, checktrainerflag_trainer
.byte 0x60
.2byte \checktrainerflag_trainer
.endm

//XSE had it wrong, i'm correcting them
.macro settrainerflag, settrainerflag_trainer
.byte 0x61
.2byte \settrainerflag_trainer
.endm

.macro cleartrainerflag, cleartrainerflag_trainer
.byte 0x62
.2byte \cleartrainerflag_trainer
.endm

.macro movesprite2, movesprite2_person, movesprite2_x, movesprite2_y
.byte 0x63
.2byte \movesprite2_person
.2byte \movesprite2_x
.2byte \movesprite2_y
.endm

.macro moveoffscreen,moveoffscreen_person
.byte 0x64
.2byte \moveoffscreen_person
.endm

.macro spritebehave,spritebehave_person,spritebehave_behaviour
.byte 0x65
.2byte \spritebehave_person
.byte \spritebehave_behavior
.endm

.macro waitmsg
.byte 0x66
.endm

.macro preparemsg,preparemsg_text
.byte 0x67
.4byte \preparemsg_text
.endm

.macro closeonkeypress
.byte 0x68
.endm

.macro lockall
.byte 0x69
.endm

.macro lock
.byte 0x6A
.endm

.macro releaseall
.byte 0x6B
.endm

.macro release
.byte 0x6C
.endm

.macro waitkeypress
.byte 0x6D
.endm

.macro yesnobox, yesnobox_x, yesnobox_y
.byte 0x6E
.byte \yesnobox_x
.byte \yesnobox_y
.endm

.macro multichoice, multichoice_x, multichoice_y, multichoice_list, multichoice_b_enabled
.byte 0x6F
.byte \multichoice_x
.byte \multichoice_y
.byte \multichoice_list
.byte \multichoice_b_enabled
.endm

.macro multichoice2, multichoice2_x, multichoice2_y, multichoice2_list, multichoice2_default_pos, multichoice2_b_enabled
.byte 0x70
.byte \multichoice2_x
.byte \multichoice2_y
.byte \multichoice2_list
.byte \multichoice2_default_pos
.byte \multichoice2_b_enabled
.endm

.macro multichoice3, multichoice3_x, multichoice3_y, multichoice3_list, multichoice3_item_per_row, multichoice3_b_enabled
.byte 0x71
.byte \multichoice3_x
.byte \multichoice3_y
.byte \multichoice3_list
.byte \multichoice3_items_per_row
.byte \multichoice3_b_enabled
.endm

.macro showbox, showbox_left_pos, showbox_top_pos, showbox_width, showbox_height
.byte 0x72
.byte \showbox_left_pos
.byte \showbox_top_pos
.byte \showbox_width
.byte \showbox_height
.endm

.macro hidebox, hidebox_left_pos, hidebox_top_pos, hidebox_width, hidebox_height
.byte 0x73
.byte \hidebox_left_pos
.byte \hidebox_top_pos
.byte \hidebox_width
.byte \hidebox_height
.endm

.macro clearbox, clearbox_left_pos, clearbox_top_pos, clearbox_width, clearbox_height
.byte 0x74
.byte \clearbox_left_pos
.byte \clearbox_top_pos
.byte \clearbox_width
.byte \clearbox_height
.endm

.macro showpokepic, showpokepic_species, showpokepic_x, showpokepic_y
.byte 0x75
.2byte \showpokepic_species
.byte \showpokepic_x
.byte \showpokepic_y
.endm

.macro hidepokepic
.byte 0x76
.endm

.macro showcontestwinner, showcontestwinner_byte
.byte 0x77
.byte \showcontestwinner_byte
.endm

.macro braille, braille_text
.byte 0x78
.4byte \braille_text
.endm

.macro givepokemon, givepokemon_species, givepokemon_level, givepokemon_item, givepokemon_unknown1, givepokemon_unknown2, givepokemon_unknown3
.byte 0x79
.2byte \givepokemon_species
.byte \givepokemon_level
.2byte \givepokemon_item
.4byte \givepokemon_unknown1
.4byte \givepokemon_unknown2
.byte \givepokemon_unknown3
.endm

.macro giveegg, giveegg_species
.byte 0x7A
.2byte \giveegg_species
.endm

.macro setpkmnpp, setpkmnpp_party_slot, setpkmnpp_attk_slot, setpkmnpp_amount, setpkmnmove
.byte 0x7B
.byte \setpkmnpp_party_slot
.byte \setpkmnpp_attk_slot
.byte \setpkmnpp_new_attk
.endm

.macro checkattack, checkattack_attack
.byte 0x7C
.2byte \checkattack_attack
.endm

.macro bufferpokemon, bufferpokemon_buffer, bufferpokemon_species
.byte 0x7D
.byte \bufferpokemon_buffer
.2byte \bufferpokemon_species
.endm

.macro bufferfirstpokemon, bufferfirstpokemon_buffer
.byte 0x7E
.byte \bufferfirstpokemon_buffer
.endm

.macro bufferpartypokemon, bufferpartypokemon_buffer, bufferpartypokemon_slot
.byte 0x7F
.byte \bufferpartypokemon_buffer
.2byte \bufferpartypokemon_slot
.endm

.macro bufferitem, bufferitem_buffer, bufferitem_item
.byte 0x80
.byte \bufferitem_buffer
.2byte \bufferitem_item
.endm

.macro bufferdecoration, bufferdecoration_buffer, bufferdecoration_decoration
.byte 0x81
.byte \bufferdecoration_buffer
.2byte \bufferdecoration_decoration
.endm

.macro bufferattack, bufferattack_buffer, bufferattack_attack
.byte 0x82
.byte \bufferattack_buffer
.2byte \bufferattack_attack
.endm

.macro buffernumber, buffernumber_buffer, buffernumber_number
.byte 0x83
.byte \buffernumber_buffer
.2byte \buffernumber_number
.endm

.macro bufferstd, bufferstd_buffer, bufferstd_string
.byte 0x84
.byte \bufferstd_buffer
.2byte \bufferstd_string
.endm

.macro bufferstring, bufferstring_buffer, bufferstring_pointer
.byte 0x85
.byte \bufferstring_buffer
.2byte \bufferstring_pointer
.endm

.macro pokemart, pokemart_pointer
.byte 0x86
.4byte \pokemart_pointer
.endm

.macro pokemart2, pokemart2_pointer
.byte 0x87
.4byte \pokemart2_pointer
.endm

.macro pokemart3, pokemart3_pointer
.byte 0x88
.4byte \pokemart3_pointer
.endm

.macro pokecasino, pokecasino_param1
.byte 0x89
.2byte \pokecasino_param1
.endm

.macro createplantedberry, plantID, berryID, berryState
.byte 0x8A
.byte \plantID
.byte \berryID
.byte \berryState
.endm

.macro choosecontestpokemon
.byte 0x8B
.endm

.macro startcontest
.byte 0x8C
.endm

.macro showcontestresults
.byte 0x8D
.endm

.macro contestlinktransfer
.byte 0x8E
.endm

.macro random, random_limit
.byte 0x8F
.2byte \random_limit
.endm

.macro givemoney, givemoney_value, givemoney_byte
.byte 0x90
.4byte \givemoney_value
.byte \givemoney_byte
.endm

.macro paymoney, paymoney_value, paymoney_byte
.byte 0x91
.4byte \paymoney_value
.byte \paymoney_byte
.endm

.macro checkmoney, checkmoney_value, checkmoney_byte
.byte 0x92
.4byte \checkmoney_value
.byte \checkmoney_byte
.endm

.macro showmoney, showmoney_x, showmoney_y
.byte 0x93
.byte \showmoney_x
.byte \showmoney_y
.endm

.macro hidemoney, hidemoney_x, hidemoney_y
.byte 0x94
.byte \hidemoney_x
.byte \hidemoney_y
.endm

.macro updatemoney, updatemoney_x, updatemoney_y
.byte 0x95
.byte \updatemoney_x
.byte \updatemoney_y
.endm

.macro checkpokenewsfor, reportID
.byte 0x96
.2byte \reportID
.endm

.macro fadescreen, fadescreen_effect
.byte 0x97
.byte \fadescreen_effect
.endm

.macro fadescreendelay, fadescreendelay_effect, fadescreendelay_time
.byte 0x98
.byte \fadescreendelay_effect
.byte \fadescreendelay_time
.endm

.macro darken, darken_size
.byte 0x99
.2byte \darken_size
.endm

.macro lighten, lighten_size
.byte 0x9A
.byte \lighten_size
.endm

.macro preparmsg2, preparemsg2_pointer
.byte 0x9B
.4byte \preparemsg2_pointer
.endm

.macro doanimation, doanimation_param
.byte 0x9C
.2byte \doanimation_param
.endm

.macro setanimation, setanimation_anim, setanimation_slot
.byte 0x9D
.byte \setanimation_anim
.2byte \setanimation_slot
.endm

.macro checkanimation, checkanimation_param
.byte 0x9E
.2byte \checkanimation_param
.endm

.macro sethealingplace, sethealingplace_param
.byte 0x9F
.2byte \sethealingplace_param
.endm

.macro checkgender
.byte 0xA0
.endm

.macro cry, cry_species, cry_effect
.byte 0xA1
.2byte \cry_species
.2byte \cry_effect
.endm

.macro setmaptile, setmaptile_x, setmaptile_y, setmaptile_tile, setmaptile_attrib
.byte 0xA2
.2byte \setmaptile_x
.2byte \setmaptile_y
.2byte \setmaptile_tile
.2byte \setmaptile_attrib
.endm

.macro resetweather
.byte 0xA3
.endm

.macro setweather,setweather_type
.byte 0xA4
.2byte \setweather_type
.endm

.macro doweather
.byte 0xA5
.endm

.macro activate_per_step_task,caseID
.byte 0xA6
.byte \caseID
.endm

.macro setmapfooter, setmapfooter_param
.byte 0xA7
.2byte \setmapfooter_param
.endm

.macro spritelevelup, spritelevelup_person, spritelevelup_bank, spritelevelup_map, spritelevelup_unknown
.byte 0xA8
.2byte \spritelevelup_person
.byte \spritelevelup_bank
.byte \spritelevelup_map
.byte \spritelevelup_unknown
.endm

.macro restorespritelevel, restorespritelevel_person, restorespritelevel_bank, restorespritelevel_map
.byte 0xA9
.2byte \restorespritelevel_person
.byte \restorespritelevel_bank
.byte \restorespritelevel_map
.endm

.macro createsprite, createsprite_sprite, createsprite_person, createsprite_x, createsprite_y, createsprite_behave, createsprite_face
.byte 0xAA
.byte \createsprite_sprite
.byte \createsprite_person
.2byte \createsprite_x
.2byte \createsprite_y
.byte \createsprite_behave
.byte \createsprite_face
.endm

.macro spriteface2, spriteface2_person, spriteface2_face
.byte 0xAB
.byte \spriteface2_person
.byte \spriteface2_face
.endm

.macro setdooropened, setdooropened_x, setdooropened_y
.byte 0xAC
.2byte \setdooropened_x
.2byte \setdooropened_y
.endm

.macro setdoorclosed, setdoorclosed_x, setdoorclosed_y
.byte 0xAD
.2byte \setdoorclosed_x
.2byte \setdoorclosed_y
.endm

.macro doorchange
.byte 0xAE
.endm

.macro setdooropened2, setdooropened2_x, setdooropened2_y
.byte 0xAF
.2byte \setdooropened2_x
.2byte \setdooropened2_y
.endm

.macro setdoorclosed2, setdoorclosed2_x, setdoorclosed2_y
.byte 0xB0
.2byte \setdoorclosed2_x
.2byte \setdoorclosed2_y
.endm

.macro cmdB1
.byte 0xB1
.endm

.macro checkcoins, checkcoins_var
.byte 0xB3
.2byte \checkcoins_var
.endm

.macro givecoins, givecoins_param
.byte 0xB4
.2byte \givecoins_param
.endm

.macro removecoins, removecoins_param
.byte 0xB5
.2byte \removecoins_param
.endm

.macro setwildbattle, setwildbattle_species, setwildbattle_level, setwildbattle_item
.byte 0xB6
.2byte \setwildbattle_species
.byte \setwildbattle_level
.2byte \setwildbattle_item
.endm

.macro dowildbattle
.byte 0xB7
.endm

.macro setvirtualaddress, setvirtualaddress_param
.byte 0xB8
.4byte \setvirtualaddress_param
.endm

.macro virtualgoto, virtualgoto_pointer
.byte 0xB9
.4byte \virtualgoto_pointer
.endm

.macro virtualcall, virtualcall_pointer
.byte 0xBA
.4byte \virtualcall_pointer
.endm

.macro virtualgotoif, virtualgotoif_condition, virtualgotoif_pointer
.byte 0xBB
.byte \virtualgotoif_condition
.4byte \virtualgotoif_pointer
.endm

.macro virtualcallif, virtualcallif_condition, virtualcallif_pointer
.byte 0xBC
.byte \virtualcallif_condition
.4byte \virtualcallif_pointer
.endm

.macro virtualmsgbox, virtualmsgbox_text
.byte 0xBD
.4byte \virtualmsgbox_text
.endm

.macro virtualloadpointer, virtualloadpointer_pointer
.byte 0xBE
.4byte \virtualloadpointer_pointer
.endm

.macro virtualbuffer, virtualbuffer_buffer, virtualbuffer_pointer
.byte 0xBF
.byte \virtualbuffer_buffer
.4byte \virtualbuffer_pointer
.endm

.macro showcoins, showcoins_x, showcoins_y
.byte 0xC0
.byte \showcoins_x
.byte \showcoins_y
.endm

.macro hidecoins, hidecoins_x, hidecoins_y
.byte 0xC1
.byte \hidecoins_x
.byte \hidecoins_y
.endm

.macro updatecoins, updatecoins_x, updatecoins_y
.byte 0xC2
.byte \updatecoins_x
.byte \updatecoins_y
.endm

.macro  increment_encrypted_counter, counterID
.byte 0xC3
.byte \counterID
.endm

.macro warp6, warp6_bank, warp6_map, warp6_warp, warp6_x, warp6_y
.byte 0xC4
.byte \warp6_bank
.byte \warp6_map
.byte \warp6_warp
.2byte \warp6_x
.2byte \warp6_y
.endm

.macro waitcry
.byte 0xC5
.endm

.macro bufferboxname, bufferboxname_buffer, bufferboxname_box
.byte 0xC6
.byte \bufferboxname_buffer
.2byte \bufferboxname_box
.endm

//.macro textcolor, textcolor_byte, nopC7
//.byte 0xC7
//.byte textcolor_byte Uncomment if FR.
//.endm

.macro cmdC8, cmdC8_param
.byte 0xC8
.4byte \cmdC8_param
.endm

.macro cmdC9
.byte 0xC9
.endm

.macro signmsg
.byte 0xCA
.endm

.macro normalmsg
.byte 0xCB
.endm

//.macro comparehiddenvar, comparehiddenvar_byte, comparehiddenvar_value, nopCC
//.byte 0xCC
//.byte comparehiddenvar_byte Uncomment if FR.
//.4byte comparehiddenvar_value
//.endm

.macro setobedience, setobedience_slot
.byte 0xCD
.2byte \setobedience_slot
.endm

.macro checkobedience, checkobedience_slot
.byte 0xCE
.2byte \checkobedience_slot
.endm

.macro executeram
.byte 0xCF
.endm

//.macro setworldmapflag, setworldmapflag_param, nopD0
//.byte 0xD0
//.2byte setworldmapflag_param uncomment if FR.
//.endm

.macro warpteleport2
.byte 0xD1
.endm

.macro setcatchlocation, setcatchlocation_slot, setcatchlocation_map
.byte 0xD2
.2byte \setcatchlocation_slot
.byte \setcatchlocation_map
.endm

.macro braille2, braille2_text
.byte 0xD3
.4byte \braille2_text
.endm

.macro bufferitems, bufferitems_buffer, bufferitems_item, bufferitems_amount
.byte \bufferitems_buffer
.2byte \bufferitems_item
.2byte \bufferitems_amount
.endm

.macro cmdD5
.byte 0xD5
.endm

.macro cmdD6
.byte 0xD6
.endm

.macro warp7, warp7_bank, warp7_map, warp7_warp, warp7_x, warp7_y
.byte 0xD7
.byte \warp7_bank
.byte \warp7_map
.byte \warp7_warp
.2byte \warp7_x
.2byte \warp7_y
.endm

.macro cmdD8
.byte 0xD8
.endm

.macro cmdD9
.byte 0xD9
.endm

.macro hidebox2
.byte 0xDA
.endm

.macro preparemsg3, preparemsg3_pointer
.byte 0xDB
.4byte \preparemsg3_pointer
.endm

.macro fadescreen3, fadescreen3_param
.byte 0xDC
.byte \fadescreen3_param
.endm

.macro buffertrainerclass, buffertrainerclass_buffer, buffertrainerclass_class
.byte 0xDD
.byte \buffertrainerclass_buffer
.2byte \buffertrainerclass_class
.endm

.macro buffertrainername, buffertrainername_buffer, buffertrainername_trainer
.byte 0xDE
.byte \buffertrainername_buffer
.2byte \buffertrainername_trainer
.endm

.macro pokenavcall, pokenavcall_text
.byte 0xDF
.4byte \pokenavcall_text
.endm

.macro warp8, warp8_bank, warp8_map, warp8_warp, warp8_x, warp8_y
.byte 0xE0
.byte \warp8_bank
.byte \warp8_map
.byte \warp8_warp
.2byte \warp8_x
.2byte \warp8_y
.endm

.macro buffercontesttype, buffercontesttype_param1, buffercontesttype_param2
.byte 0xE1
.byte \buffercontesttype_param1
.2byte \buffercontesttype_param2
.endm

.macro bufferitems2, bufferitems2_buffer, bufferitems2_item, bufferitems2_amount
.byte 0xE2
.byte \bufferitems2_buffer
.2byte \bufferitems2_item
.2byte \bufferitems2_amount
.endm
