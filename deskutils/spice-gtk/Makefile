# Created by olevole@olevole.ru
# $FreeBSD:$

PORTNAME=	spice-gtk
PORTVERSION=	0.26
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.spice-space.org/download/gtk/

MAINTAINER=	olevole@olevole.ru
COMMENT=	Gtk client and libraries for SPICE remote desktop servers

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg

USE_XORG=	pixman
USE_GNOME=	gnomeprefix gtk20 gtk30 intltool introspection
USES=		gmake libtool pkgconfig python tar:bzip2

CONFIGURE_ENV+=	SSL_CFLAGS=-I${OPENSSLINC} \
		SSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	SASL
OPTIONS_DEFAULT=GSTREAMER SASL

OPTIONS_RADIO=		AUDIO
OPTIONS_RADIO_AUDIO=	GSTREAMER PULSEAUDIO NOAUDIO

NOAUDIO_DESC=		Disable audio backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
CONFIGURE_ARGS+=		--with-audio=gstreamer
USE_GSTREAMER=			yes
.elif ${PORT_OPTIONS:MPULSEAUDIO}
CONFIGURE_ARGS+=		--with-audio=pulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse
.elif ${PORT_OPTIONS:MNOAUDIO}
CONFIGURE_ARGS+=	--with-audio=no
.endif
.if ${PORT_OPTIONS:MSASL}
CONFIGURE_ARGS+=	--with-sasl=yes
SASL_LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
LIB_DEPENDS+=		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
.else
CONFIGURE_ARGS+=	--with-sasl=no
.endif

.include <bsd.port.mk>
