#ifndef _SQUIRREL_API_H
#define _SQUIRREL_API_H

/*vm*/
#define sq_open SqModule::api->open
#define sq_newthread SqModule::api->newthread
#define sq_seterrorhandler SqModule::api->seterrorhandler
#define sq_close SqModule::api->close
#define sq_setforeignptr SqModule::api->setforeignptr
#define sq_getforeignptr SqModule::api->getforeignptr
#define sq_setsharedforeignptr SqModule::api->setsharedforeignptr
#define sq_getsharedforeignptr SqModule::api->getsharedforeignptr
#define sq_setvmreleasehook SqModule::api->setvmreleasehook
#define sq_getvmreleasehook SqModule::api->getvmreleasehook
#define sq_setsharedreleasehook SqModule::api->setsharedreleasehook
#define sq_getsharedreleasehook SqModule::api->getsharedreleasehook
#define sq_setprintfunc SqModule::api->setprintfunc
#define sq_getprintfunc SqModule::api->getprintfunc
#define sq_geterrorfunc SqModule::api->geterrorfunc
#define sq_suspendvm SqModule::api->suspendvm
#define sq_wakeupvm SqModule::api->wakeupvm
#define sq_getvmstate SqModule::api->getvmstate
#define sq_getversion SqModule::api->getversion

/*compiler*/
#define sq_compile SqModule::api->compile
#define sq_compilebuffer SqModule::api->compilebuffer
#define sq_enabledebuginfo SqModule::api->enabledebuginfo
#define sq_notifyallexceptions SqModule::api->notifyallexceptions
#define sq_setcompilererrorhandler SqModule::api->setcompilererrorhandler

/*stack operations*/
#define sq_push SqModule::api->push
#define sq_pop SqModule::api->pop
#define sq_poptop SqModule::api->poptop
#define sq_remove SqModule::api->remove
#define sq_gettop SqModule::api->gettop
#define sq_settop SqModule::api->settop
#define sq_reservestack SqModule::api->reservestack
#define sq_cmp SqModule::api->cmp
#define sq_move SqModule::api->move

/*object creation handling*/
#define sq_newuserdata SqModule::api->newuserdata
#define sq_newtable SqModule::api->newtable
#define sq_newtableex SqModule::api->newtableex
#define sq_newarray SqModule::api->newarray
#define sq_newclosure SqModule::api->newclosure
#define sq_setparamscheck SqModule::api->setparamscheck
#define sq_bindenv SqModule::api->bindenv
#define sq_setclosureroot SqModule::api->setclosureroot
#define sq_getclosureroot SqModule::api->getclosureroot
#define sq_pushstring SqModule::api->pushstring
#define sq_pushfloat SqModule::api->pushfloat
#define sq_pushinteger SqModule::api->pushinteger
#define sq_pushbool SqModule::api->pushbool
#define sq_pushuserpointer SqModule::api->pushuserpointer
#define sq_pushnull SqModule::api->pushnull
#define sq_pushthread SqModule::api->pushthread
#define sq_gettype SqModule::api->gettype
#define sq_typeof SqModule::api->type_of
#define sq_getsize SqModule::api->getsize
#define sq_gethash SqModule::api->gethash
#define sq_getbase SqModule::api->getbase
#define sq_instanceof SqModule::api->instanceof
#define sq_tostring SqModule::api->tostring
#define sq_tobool SqModule::api->tobool
#define sq_getstring SqModule::api->getstring
#define sq_getinteger SqModule::api->getinteger
#define sq_getfloat SqModule::api->getfloat
#define sq_getbool SqModule::api->getbool
#define sq_getthread SqModule::api->getthread
#define sq_getuserpointer SqModule::api->getuserpointer
#define sq_getuserdata SqModule::api->getuserdata
#define sq_settypetag SqModule::api->settypetag
#define sq_gettypetag SqModule::api->gettypetag
#define sq_setreleasehook SqModule::api->setreleasehook
#define sq_getreleasehook SqModule::api->getreleasehook
#define sq_getscratchpad SqModule::api->getscratchpad
#define sq_getfunctioninfo SqModule::api->getfunctioninfo
#define sq_getclosureinfo SqModule::api->getclosureinfo
#define sq_getclosurename SqModule::api->getclosurename
#define sq_setnativeclosurename SqModule::api->setnativeclosurename
#define sq_setinstanceup SqModule::api->setinstanceup
#define sq_getinstanceup SqModule::api->getinstanceup
#define sq_setclassudsize SqModule::api->setclassudsize
#define sq_newclass SqModule::api->newclass
#define sq_createinstance SqModule::api->createinstance
#define sq_setattributes SqModule::api->setattributes
#define sq_getattributes SqModule::api->getattributes
#define sq_getclass SqModule::api->getclass
#define sq_weakref SqModule::api->weakref
#define sq_getdefaultdelegate SqModule::api->getdefaultdelegate
#define sq_getmemberhandle SqModule::api->getmemberhandle
#define sq_getbyhandle SqModule::api->getbyhandle
#define sq_setbyhandle SqModule::api->setbyhandle

/*object manipulation*/
#define sq_pushroottable SqModule::api->pushroottable
#define sq_pushregistrytable SqModule::api->pushregistrytable
#define sq_pushconsttable SqModule::api->pushconsttable
#define sq_setroottable SqModule::api->setroottable
#define sq_setconsttable SqModule::api->setconsttable
#define sq_newslot SqModule::api->newslot
#define sq_deleteslot SqModule::api->deleteslot
#define sq_set SqModule::api->set
#define sq_get SqModule::api->get
#define sq_rawset SqModule::api->rawset
#define sq_rawget SqModule::api->rawget
#define sq_rawdeleteslot SqModule::api->rawdeleteslot
#define sq_newmember SqModule::api->newmember
#define sq_rawnewmember SqModule::api->rawnewmember
#define sq_arrayappend SqModule::api->arrayappend
#define sq_arraypop SqModule::api->arraypop
#define sq_arrayresize SqModule::api->arrayresize
#define sq_arrayreverse SqModule::api->arrayreverse
#define sq_arrayremove SqModule::api->arrayremove
#define sq_arrayinsert SqModule::api->arrayinsert
#define sq_setdelegate SqModule::api->setdelegate
#define sq_getdelegate SqModule::api->getdelegate
#define sq_clone SqModule::api->clone
#define sq_setfreevariable SqModule::api->setfreevariable
#define sq_next SqModule::api->next
#define sq_getweakrefval SqModule::api->getweakrefval
#define sq_clear SqModule::api->clear

/*calls*/
#define sq_call SqModule::api->call
#define sq_resume SqModule::api->resume
#define sq_getlocal SqModule::api->getlocal
#define sq_getcallee SqModule::api->getcallee
#define sq_getfreevariable SqModule::api->getfreevariable
#define sq_throwerror SqModule::api->throwerror
#define sq_throwobject SqModule::api->throwobject
#define sq_reseterror SqModule::api->reseterror
#define sq_getlasterror SqModule::api->getlasterror

/*raw object handling*/
#define sq_getstackobj SqModule::api->getstackobj
#define sq_pushobject SqModule::api->pushobject
#define sq_addref SqModule::api->addref
#define sq_release SqModule::api->release
#define sq_getrefcount SqModule::api->getrefcount
#define sq_resetobject SqModule::api->resetobject
#define sq_objtostring SqModule::api->objtostring
#define sq_objtobool SqModule::api->objtobool
#define sq_objtointeger SqModule::api->objtointeger
#define sq_objtofloat SqModule::api->objtofloat
#define sq_objtouserpointer SqModule::api->objtouserpointer
#define sq_getobjtypetag SqModule::api->getobjtypetag
#define sq_getvmrefcount SqModule::api->getvmrefcount

/*GC*/
#define sq_collectgarbage SqModule::api->collectgarbage
#define sq_resurrectunreachable SqModule::api->resurrectunreachable

/*serialization*/
#define sq_writeclosure SqModule::api->writeclosure
#define sq_readclosure SqModule::api->readclosure

/*mem allocation*/
#define sq_malloc SqModule::api->malloc
#define sq_realloc SqModule::api->realloc
#define sq_free SqModule::api->free

/*debug*/
#define sq_stackinfos SqModule::api->stackinfos
#define sq_setdebughook SqModule::api->setdebughook
#define sq_setnativedebughook SqModule::api->setnativedebughook

#endif
