# $FreeBSD: head/devel/lua-lpeg/Makefile 390265 2015-06-21 22:03:52Z antoine $

PORTNAME=	lpeg
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	http://www.inf.puc-rio.br/~roberto/lpeg/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	olevole@olevole.ru
COMMENT=	Parsing Expression Grammars For Lua

LICENSE=	MIT

ALL_TARGET=	linux
CFLAGS+=	-DLUA_32BITS
MAKE_ARGS=	CC=${CC} LUADIR=${LUA_INCDIR}
MAKEFILE=	${WRKSRC}/makefile
USES?=		lua

PLIST_FILES=	%%LUA_MODLIBDIR%%/lpeg.so

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
