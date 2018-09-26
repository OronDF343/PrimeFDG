#pragma once

#include "stdafx.h"

// The prime from which to start the sieveing loop
#define PFDG_PATTERN_SKIP 13
// The length of the precomputed pattern
#define PFDG_PATTERN_LENGTH 1155
// The prefix of the precomputed pattern
const BITARRAY_WORD pfdg_pattern_prefix = 0x7E92ED659B4B3491;
// The precomputed pattern data
const BITARRAY_WORD pfdg_pattern[PFDG_PATTERN_LENGTH] =
{
	0xD6693DF279A5B3CD,
	0x4B669EDDA5DACB36,
	0xB5967D2ED279ECB3,
	0xF3C9669ECD35BA4F,
	0x6B75976B2CDAD9B4,
	0xB4B749E792CF2DDA,
	0x9A5B36D6E92ED759,
	0x5DECBB6966B3CF25,
	0x279E6B34B6E9BDD2,
	0xD75BA4BB5B66D2CD,
	0xDDA79A4F3C97696C,
	0x6CDAD9A6B74D76B2,
	0x92ED659BCB349E79,
	0x69BCF25BA5F34D6F,
	0x669ADD2DDBCB3696,
	0x9E6D2CF27DE4B35B,
	0xE96696CD35BA4BF5,
	0xF4976B2CDA59A5F3,
	0xB349EF93CD2D9E6B,
	0x5B34F6ED2ED659B6,
	0xACB3E97693CF659A,
	0x9E4B34F669ADD27D,
	0x5BACBB5966D6CDA7,
	0xA5BA4F3C96796ED3,
	0xD2D9B6B74976BACD,
	0xEF65DB4B359E792C,
	0x3CF359A5B74DEE92,
	0xBADD25DADB369669,
	0xED3CD279E4BB4B66,
	0x66D6CD35BA6BB596,
	0x976B2CDE59A4F3CB,
	0x4DE792DD2F9A6B7C,
	0x34D6E96EDE59B4B3,
	0xF3696793EF259ADB,
	0x4B34B669ADD25FAC,
	0xA4BB5966D2CD2F9F,
	0x9A4F7C9E696CF35F,
	0xD9A7B76976B2CDB5,
	0x659F4BB49E7B2CD2,
	0xF259A7B34D6E93ED,
	0xDD65DACB36B66D3C,
	0x2DD279E4B3CB769A,
	0x96CDB5BA4BB5D66D,
	0x7B2EDA59ACF3C966,
	0xE79ACD2DBA6F7497,
	0xD6E92ED6D9B4B349,
	0x69E693CF25DA5B35,
	0x36B669ADD35DACB7,
	0xBB5966F2CD279E5B,
	0x6F3C96E97CD35BE4,
	0xA6B74B76F2CDA59A,
	0x9B4B3C9F792CD6D9,
	0x59A5B34D6E92FD67,
	0x25DACB3696697CFA,
	0xD27BE4F34B679AFD,
	0xCD3DBB4BB5966DAC,
	0x2CFA5DA4F3D96696,
	0x92CD3D9A6B749F6B,
	0xEB2ED659B5B369E7,
	0x6E93CF259E5BB4D6,
	0xB66DADD25DAEB369,
	0xD976D2CD679E4B34,
	0x3CD6696DD37BA4BB,
	0xB74976B6CDA59A4F,
	0x4F349E792ED2D9AE,
	0xB5B34D6E9AED65BB,
	0xDACB3796693CF2D9,
	0x79E4B74BE69ADF25,
	0x35BA5BB7966D2CD3,
	0xDA59E4FBC966B6CD,
	0xCD2D9A6B7497EB3C,
	0x2ED659B4B34BE7D2,
	0x93DF279A5B3CD7E9,
	0x69EDDA5DACB36D66,
	0x67D2ED279ECB34B6,
	0x9669ECD35BA4FB59,
	0x5976B2CDAD9B4F3C,
	0x749E792CF2DDA6B7,
	0xB36D6E92ED759B4B,
	0xCBB6966B3CF259A5,
	0xE6B34B6E9BDD25DE,
	0xBA4BB5B66D2CD279,
	0x79A4F3C97696CD75,
	0xAD9A6B74D76B2DDA,
	0xD659BCB349E796CD,
	0xCF25BA5F34D6F92E,
	0xADD2DDBCB369669B,
	0xD2CF27DE4B35B669,
	0x696CD35BA4BF59E6,
	0x76B2CDA59A5F3E96,
	0x9EF93CD2D9E6BF49,
	0x4F6ED2ED659B6B34,
	0x3E97693CF659A5B3,
	0xB34F669ADD27DACB,
	0xCBB5966D6CDA79E4,
	0xA4F3C96796ED35BA,
	0x9B6B74976BACDA5B,
	0x5DB4B359E792CD2D,
	0x359A5B74DEE92EF6,
	0xD25DADB3696693CF,
	0xCD279E4BB4B66BAD,
	0x6CD35BA6BB596ED3,
	0xB2CDE59A4F3CB66D,
	0x792DD2F9A6B7C976,
	0x6E96EDE59B4B34DE,
	0x96793EF259ADB34D,
	0x4B669ADD25FACF36,
	0xB5966D2CD2F9F4B3,
	0xF7C9E696CF35FA4B,
	0x7B76976B2CDB59A4,
	0xF4BB49E7B2CD2D9A,
	0x9A7B34D6E93ED659,
	0x5DACB36B66D3CF25,
	0x279E4B3CB769ADD6,
	0xDB5BA4BB5D66D2DD,
	0xEDA59ACF3C96696C,
	0xACD2DBA6F74977B2,
	0x92ED6D9B4B349E79,
	0x693CF25DA5B35D6E,
	0x669ADD35DACB769E,
	0x966F2CD279E5B36B,
	0xC96E97CD35BE4BB5,
	0x74B76F2CDA59A6F3,
	0xB3C9F792CD6D9A6B,
	0x5B34D6E92FD679B4,
	0xACB3696697CFA59A,
	0xBE4F34B679AFD25D,
	0xDBB4BB5966DACD27,
	0xA5DA4F3D96696CD3,
	0xD3D9A6B749F6B2CF,
	0xED659B5B369E792C,
	0x3CF259E5BB4D6EB2,
	0xDADD25DAEB3696E9,
	0x6D2CD679E4B34B66,
	0x6696DD37BA4BBD97,
	0x976B6CDA59A4F3CD,
	0x49E792ED2D9AEB74,
	0x34D6E9AED65BB4F3,
	0xB3796693CF2D9B5B,
	0x4B74BE69ADF25DAC,
	0xA5BB7966D2CD379E,
	0x9E4FBC966B6CD35B,
	0xD9A6B7497EB3CDA5,
	0x659B4B34BE7D2CD2,
	0xF279A5B3CD7E92ED,
	0xDDA5DACB36D6693D,
	0x2ED279ECB34B669E,
	0x9ECD35BA4FB5967D,
	0x6B2CDAD9B4F3C966,
	0xE792CF2DDA6B7597,
	0xD6E92ED759B4B749,
	0x6966B3CF259A5B36,
	0x34B6E9BDD25DECBB,
	0xBB5B66D2CD279E6B,
	0x4F3C97696CD75BA4,
	0xA6B74D76B2DDA79A,
	0x9BCB349E796CDAD9,
	0x5BA5F34D6F92ED65,
	0x2DDBCB369669BCF2,
	0xF27DE4B35B669ADD,
	0xCD35BA4BF59E6D2C,
	0x2CDA59A5F3E96696,
	0x93CD2D9E6BF4976B,
	0xED2ED659B6B349EF,
	0x7693CF659A5B34F6,
	0xF669ADD27DACB3E9,
	0x5966D6CDA79E4B34,
	0x3C96796ED35BACBB,
	0xB74976BACDA5BA4F,
	0x4B359E792CD2D9B6,
	0xA5B74DEE92EF65DB,
	0xDADB3696693CF359,
	0x79E4BB4B66BADD25,
	0x35BA6BB596ED3CD2,
	0xDE59A4F3CB66D6CD,
	0xDD2F9A6B7C976B2C,
	0x6EDE59B4B34DE792,
	0x93EF259ADB34D6E9,
	0x69ADD25FACF36967,
	0x66D2CD2F9F4B34B6,
	0x9E696CF35FA4BB59,
	0x6976B2CDB59A4F7C,
	0xB49E7B2CD2D9A7B7,
	0xB34D6E93ED659F4B,
	0xCB36B66D3CF259A7,
	0xE4B3CB769ADD65DA,
	0xBA4BB5D66D2DD279,
	0x59ACF3C96696CDB5,
	0x2DBA6F74977B2EDA,
	0xD6D9B4B349E79ACD,
	0xCF25DA5B35D6E92E,
	0xADD35DACB769E693,
	0xF2CD279E5B36B669,
	0xE97CD35BE4BB5966,
	0x76F2CDA59A6F3C96,
	0x9F792CD6D9A6B74B,
	0x4D6E92FD679B4B3C,
	0x3696697CFA59A5B3,
	0xF34B679AFD25DACB,
	0x4BB5966DACD27BE4,
	0xA4F3D96696CD3DBB,
	0x9A6B749F6B2CFA5D,
	0x59B5B369E792CD3D,
	0x259E5BB4D6EB2ED6,
	0xD25DAEB3696E93CF,
	0xCD679E4B34B66DAD,
	0x6DD37BA4BBD976D2,
	0xB6CDA59A4F3CD669,
	0x792ED2D9AEB74976,
	0x6E9AED65BB4F349E,
	0x96693CF2D9B5B34D,
	0x4BE69ADF25DACB37,
	0xB7966D2CD379E4B7,
	0xFBC966B6CD35BA5B,
	0x6B7497EB3CDA59E4,
	0xB4B34BE7D2CD2D9A,
	0x9A5B3CD7E92ED659,
	0x5DACB36D6693DF27,
	0x279ECB34B669EDDA,
	0xD35BA4FB5967D2ED,
	0xCDAD9B4F3C9669EC,
	0x2CF2DDA6B75976B2,
	0x92ED759B4B749E79,
	0x6B3CF259A5B36D6E,
	0x6E9BDD25DECBB696,
	0xB66D2CD279E6B34B,
	0xC97696CD75BA4BB5,
	0x74D76B2DDA79A4F3,
	0xB349E796CDAD9A6B,
	0x5F34D6F92ED659BC,
	0xBCB369669BCF25BA,
	0xDE4B35B669ADD2DD,
	0x5BA4BF59E6D2CF27,
	0xA59A5F3E96696CD3,
	0xD2D9E6BF4976B2CD,
	0xED659B6B349EF93C,
	0x3CF659A5B34F6ED2,
	0x9ADD27DACB3E9769,
	0x6D6CDA79E4B34F66,
	0x6796ED35BACBB596,
	0x976BACDA5BA4F3C9,
	0x59E792CD2D9B6B74,
	0x74DEE92EF65DB4B3,
	0xB3696693CF359A5B,
	0x4BB4B66BADD25DAD,
	0xA6BB596ED3CD279E,
	0x9A4F3CB66D6CD35B,
	0xF9A6B7C976B2CDE5,
	0xE59B4B34DE792DD2,
	0xF259ADB34D6E96ED,
	0xDD25FACF3696793E,
	0x2CD2F9F4B34B669A,
	0x96CF35FA4BB5966D,
	0x6B2CDB59A4F7C9E6,
	0xE7B2CD2D9A7B7697,
	0xD6E93ED659F4BB49,
	0x6B66D3CF259A7B34,
	0x3CB769ADD65DACB3,
	0xBB5D66D2DD279E4B,
	0xCF3C96696CDB5BA4,
	0xA6F74977B2EDA59A,
	0x9B4B349E79ACD2DB,
	0x5DA5B35D6E92ED6D,
	0x35DACB769E693CF2,
	0xD279E5B36B669ADD,
	0xCD35BE4BB5966F2C,
	0x2CDA59A6F3C96E97,
	0x92CD6D9A6B74B76F,
	0xE92FD679B4B3C9F7,
	0x6697CFA59A5B34D6,
	0xB679AFD25DACB369,
	0x5966DACD27BE4F34,
	0x3D96696CD3DBB4BB,
	0xB749F6B2CFA5DA4F,
	0x5B369E792CD3D9A6,
	0xE5BB4D6EB2ED659B,
	0xDAEB3696E93CF259,
	0x79E4B34B66DADD25,
	0x37BA4BBD976D2CD6,
	0xDA59A4F3CD6696DD,
	0xED2D9AEB74976B6C,
	0xAED65BB4F349E792,
	0x93CF2D9B5B34D6E9,
	0x69ADF25DACB37966,
	0x66D2CD379E4B74BE,
	0x966B6CD35BA5BB79,
	0x497EB3CDA59E4FBC,
	0x34BE7D2CD2D9A6B7,
	0xB3CD7E92ED659B4B,
	0xCB36D6693DF279A5,
	0xECB34B669EDDA5DA,
	0xBA4FB5967D2ED279,
	0xD9B4F3C9669ECD35,
	0x2DDA6B75976B2CDA,
	0xD759B4B749E792CF,
	0xCF259A5B36D6E92E,
	0xBDD25DECBB6966B3,
	0xD2CD279E6B34B6E9,
	0x696CD75BA4BB5B66,
	0x76B2DDA79A4F3C97,
	0x9E796CDAD9A6B74D,
	0x4D6F92ED659BCB34,
	0x369669BCF25BA5F3,
	0xB35B669ADD2DDBCB,
	0x4BF59E6D2CF27DE4,
	0xA5F3E96696CD35BA,
	0x9E6BF4976B2CDA59,
	0x59B6B349EF93CD2D,
	0x659A5B34F6ED2ED6,
	0xD27DACB3E97693CF,
	0xCDA79E4B34F669AD,
	0x6ED35BACBB5966D6,
	0xBACDA5BA4F3C9679,
	0x792CD2D9B6B74976,
	0xEE92EF65DB4B359E,
	0x96693CF359A5B74D,
	0x4B66BADD25DADB36,
	0xB596ED3CD279E4BB,
	0xF3CB66D6CD35BA6B,
	0x6B7C976B2CDE59A4,
	0xB4B34DE792DD2F9A,
	0x9ADB34D6E96EDE59,
	0x5FACF3696793EF25,
	0x2F9F4B34B669ADD2,
	0xF35FA4BB5966D2CD,
	0xCDB59A4F7C9E696C,
	0x2CD2D9A7B76976B2,
	0x93ED659F4BB49E7B,
	0x6D3CF259A7B34D6E,
	0x769ADD65DACB36B6,
	0xD66D2DD279E4B3CB,
	0xC96696CDB5BA4BB5,
	0x74977B2EDA59ACF3,
	0xB349E79ACD2DBA6F,
	0x5B35D6E92ED6D9B4,
	0xACB769E693CF25DA,
	0x9E5B36B669ADD35D,
	0x5BE4BB5966F2CD27,
	0xA59A6F3C96E97CD3,
	0xD6D9A6B74B76F2CD,
	0xFD679B4B3C9F792C,
	0x7CFA59A5B34D6E92,
	0x9AFD25DACB369669,
	0x6DACD27BE4F34B67,
	0x6696CD3DBB4BB596,
	0x9F6B2CFA5DA4F3D9,
	0x69E792CD3D9A6B74,
	0xB4D6EB2ED659B5B3,
	0xB3696E93CF259E5B,
	0x4B34B66DADD25DAE,
	0xA4BBD976D2CD679E,
	0x9A4F3CD6696DD37B,
	0xD9AEB74976B6CDA5,
	0x65BB4F349E792ED2,
	0xF2D9B5B34D6E9AED,
	0xDF25DACB3796693C,
	0x2CD379E4B74BE69A,
	0xB6CD35BA5BB7966D,
	0xEB3CDA59E4FBC966,
	0xE7D2CD2D9A6B7497,
	0xD7E92ED659B4B34B,
	0x6D6693DF279A5B3C,
	0x34B669EDDA5DACB3,
	0xFB5967D2ED279ECB,
	0x4F3C9669ECD35BA4,
	0xA6B75976B2CDAD9B,
	0x9B4B749E792CF2DD,
	0x59A5B36D6E92ED75,
	0x25DECBB6966B3CF2,
	0xD279E6B34B6E9BDD,
	0xCD75BA4BB5B66D2C,
	0x2DDA79A4F3C97696,
	0x96CDAD9A6B74D76B,
	0xF92ED659BCB349E7,
	0x669BCF25BA5F34D6,
	0xB669ADD2DDBCB369,
	0x59E6D2CF27DE4B35,
	0x3E96696CD35BA4BF,
	0xBF4976B2CDA59A5F,
	0x6B349EF93CD2D9E6,
	0xA5B34F6ED2ED659B,
	0xDACB3E97693CF659,
	0x79E4B34F669ADD27,
	0x35BACBB5966D6CDA,
	0xDA5BA4F3C96796ED,
	0xCD2D9B6B74976BAC,
	0x2EF65DB4B359E792,
	0x93CF359A5B74DEE9,
	0x6BADD25DADB36966,
	0x6ED3CD279E4BB4B6,
	0xB66D6CD35BA6BB59,
	0xC976B2CDE59A4F3C,
	0x34DE792DD2F9A6B7,
	0xB34D6E96EDE59B4B,
	0xCF3696793EF259AD,
	0xF4B34B669ADD25FA,
	0xFA4BB5966D2CD2F9,
	0x59A4F7C9E696CF35,
	0x2D9A7B76976B2CDB,
	0xD659F4BB49E7B2CD,
	0xCF259A7B34D6E93E,
	0xADD65DACB36B66D3,
	0xD2DD279E4B3CB769,
	0x696CDB5BA4BB5D66,
	0x77B2EDA59ACF3C96,
	0x9E79ACD2DBA6F749,
	0x5D6E92ED6D9B4B34,
	0x769E693CF25DA5B3,
	0xB36B669ADD35DACB,
	0x4BB5966F2CD279E5,
	0xA6F3C96E97CD35BE,
	0x9A6B74B76F2CDA59,
	0x79B4B3C9F792CD6D,
	0xA59A5B34D6E92FD6,
	0xD25DACB3696697CF,
	0xCD27BE4F34B679AF,
	0x6CD3DBB4BB5966DA,
	0xB2CFA5DA4F3D9669,
	0x792CD3D9A6B749F6,
	0x6EB2ED659B5B369E,
	0x96E93CF259E5BB4D,
	0x4B66DADD25DAEB36,
	0xBD976D2CD679E4B3,
	0xF3CD6696DD37BA4B,
	0xEB74976B6CDA59A4,
	0xB4F349E792ED2D9A,
	0x9B5B34D6E9AED65B,
	0x5DACB3796693CF2D,
	0x379E4B74BE69ADF2,
	0xD35BA5BB7966D2CD,
	0xCDA59E4FBC966B6C,
	0x2CD2D9A6B7497EB3,
	0x92ED659B4B34BE7D,
	0x693DF279A5B3CD7E,
	0x669EDDA5DACB36D6,
	0x967D2ED279ECB34B,
	0xC9669ECD35BA4FB5,
	0x75976B2CDAD9B4F3,
	0xB749E792CF2DDA6B,
	0x5B36D6E92ED759B4,
	0xECBB6966B3CF259A,
	0x9E6B34B6E9BDD25D,
	0x5BA4BB5B66D2CD27,
	0xA79A4F3C97696CD7,
	0xDAD9A6B74D76B2DD,
	0xED659BCB349E796C,
	0xBCF25BA5F34D6F92,
	0x9ADD2DDBCB369669,
	0x6D2CF27DE4B35B66,
	0x6696CD35BA4BF59E,
	0x976B2CDA59A5F3E9,
	0x49EF93CD2D9E6BF4,
	0x34F6ED2ED659B6B3,
	0xB3E97693CF659A5B,
	0x4B34F669ADD27DAC,
	0xACBB5966D6CDA79E,
	0xBA4F3C96796ED35B,
	0xD9B6B74976BACDA5,
	0x65DB4B359E792CD2,
	0xF359A5B74DEE92EF,
	0xDD25DADB3696693C,
	0x3CD279E4BB4B66BA,
	0xD6CD35BA6BB596ED,
	0x6B2CDE59A4F3CB66,
	0xE792DD2F9A6B7C97,
	0xD6E96EDE59B4B34D,
	0x696793EF259ADB34,
	0x34B669ADD25FACF3,
	0xBB5966D2CD2F9F4B,
	0x4F7C9E696CF35FA4,
	0xA7B76976B2CDB59A,
	0x9F4BB49E7B2CD2D9,
	0x59A7B34D6E93ED65,
	0x65DACB36B66D3CF2,
	0xD279E4B3CB769ADD,
	0xCDB5BA4BB5D66D2D,
	0x2EDA59ACF3C96696,
	0x9ACD2DBA6F74977B,
	0xE92ED6D9B4B349E7,
	0xE693CF25DA5B35D6,
	0xB669ADD35DACB769,
	0x5966F2CD279E5B36,
	0x3C96E97CD35BE4BB,
	0xB74B76F2CDA59A6F,
	0x4B3C9F792CD6D9A6,
	0xA5B34D6E92FD679B,
	0xDACB3696697CFA59,
	0x7BE4F34B679AFD25,
	0x3DBB4BB5966DACD2,
	0xFA5DA4F3D96696CD,
	0xCD3D9A6B749F6B2C,
	0x2ED659B5B369E792,
	0x93CF259E5BB4D6EB,
	0x6DADD25DAEB3696E,
	0x76D2CD679E4B34B6,
	0xD6696DD37BA4BBD9,
	0x4976B6CDA59A4F3C,
	0x349E792ED2D9AEB7,
	0xB34D6E9AED65BB4F,
	0xCB3796693CF2D9B5,
	0xE4B74BE69ADF25DA,
	0xBA5BB7966D2CD379,
	0x59E4FBC966B6CD35,
	0x2D9A6B7497EB3CDA,
	0xD659B4B34BE7D2CD,
	0xDF279A5B3CD7E92E,
	0xEDDA5DACB36D6693,
	0xD2ED279ECB34B669,
	0x69ECD35BA4FB5967,
	0x76B2CDAD9B4F3C96,
	0x9E792CF2DDA6B759,
	0x6D6E92ED759B4B74,
	0xB6966B3CF259A5B3,
	0xB34B6E9BDD25DECB,
	0x4BB5B66D2CD279E6,
	0xA4F3C97696CD75BA,
	0x9A6B74D76B2DDA79,
	0x59BCB349E796CDAD,
	0x25BA5F34D6F92ED6,
	0xD2DDBCB369669BCF,
	0xCF27DE4B35B669AD,
	0x6CD35BA4BF59E6D2,
	0xB2CDA59A5F3E9669,
	0xF93CD2D9E6BF4976,
	0x6ED2ED659B6B349E,
	0x97693CF659A5B34F,
	0x4F669ADD27DACB3E,
	0xB5966D6CDA79E4B3,
	0xF3C96796ED35BACB,
	0x6B74976BACDA5BA4,
	0xB4B359E792CD2D9B,
	0x9A5B74DEE92EF65D,
	0x5DADB3696693CF35,
	0x279E4BB4B66BADD2,
	0xD35BA6BB596ED3CD,
	0xCDE59A4F3CB66D6C,
	0x2DD2F9A6B7C976B2,
	0x96EDE59B4B34DE79,
	0x793EF259ADB34D6E,
	0x669ADD25FACF3696,
	0x966D2CD2F9F4B34B,
	0xC9E696CF35FA4BB5,
	0x76976B2CDB59A4F7,
	0xBB49E7B2CD2D9A7B,
	0x7B34D6E93ED659F4,
	0xACB36B66D3CF259A,
	0x9E4B3CB769ADD65D,
	0x5BA4BB5D66D2DD27,
	0xA59ACF3C96696CDB,
	0xD2DBA6F74977B2ED,
	0xED6D9B4B349E79AC,
	0x3CF25DA5B35D6E92,
	0x9ADD35DACB769E69,
	0x6F2CD279E5B36B66,
	0x6E97CD35BE4BB596,
	0xB76F2CDA59A6F3C9,
	0xC9F792CD6D9A6B74,
	0x34D6E92FD679B4B3,
	0xB3696697CFA59A5B,
	0x4F34B679AFD25DAC,
	0xB4BB5966DACD27BE,
	0xDA4F3D96696CD3DB,
	0xD9A6B749F6B2CFA5,
	0x659B5B369E792CD3,
	0xF259E5BB4D6EB2ED,
	0xDD25DAEB3696E93C,
	0x2CD679E4B34B66DA,
	0x96DD37BA4BBD976D,
	0x6B6CDA59A4F3CD66,
	0xE792ED2D9AEB7497,
	0xD6E9AED65BB4F349,
	0x796693CF2D9B5B34,
	0x74BE69ADF25DACB3,
	0xBB7966D2CD379E4B,
	0x4FBC966B6CD35BA5,
	0xA6B7497EB3CDA59E,
	0x9B4B34BE7D2CD2D9,
	0x79A5B3CD7E92ED65,
	0xA5DACB36D6693DF2,
	0xD279ECB34B669EDD,
	0xCD35BA4FB5967D2E,
	0x2CDAD9B4F3C9669E,
	0x92CF2DDA6B75976B,
	0xE92ED759B4B749E7,
	0x66B3CF259A5B36D6,
	0xB6E9BDD25DECBB69,
	0x5B66D2CD279E6B34,
	0x3C97696CD75BA4BB,
	0xB74D76B2DDA79A4F,
	0xCB349E796CDAD9A6,
	0xA5F34D6F92ED659B,
	0xDBCB369669BCF25B,
	0x7DE4B35B669ADD2D,
	0x35BA4BF59E6D2CF2,
	0xDA59A5F3E96696CD,
	0xCD2D9E6BF4976B2C,
	0x2ED659B6B349EF93,
	0x93CF659A5B34F6ED,
	0x69ADD27DACB3E976,
	0x66D6CDA79E4B34F6,
	0x96796ED35BACBB59,
	0x4976BACDA5BA4F3C,
	0x359E792CD2D9B6B7,
	0xB74DEE92EF65DB4B,
	0xDB3696693CF359A5,
	0xE4BB4B66BADD25DA,
	0xBA6BB596ED3CD279,
	0x59A4F3CB66D6CD35,
	0x2F9A6B7C976B2CDE,
	0xDE59B4B34DE792DD,
	0xEF259ADB34D6E96E,
	0xADD25FACF3696793,
	0xD2CD2F9F4B34B669,
	0x696CF35FA4BB5966,
	0x76B2CDB59A4F7C9E,
	0x9E7B2CD2D9A7B769,
	0x4D6E93ED659F4BB4,
	0x36B66D3CF259A7B3,
	0xB3CB769ADD65DACB,
	0x4BB5D66D2DD279E4,
	0xACF3C96696CDB5BA,
	0xBA6F74977B2EDA59,
	0xD9B4B349E79ACD2D,
	0x25DA5B35D6E92ED6,
	0xD35DACB769E693CF,
	0xCD279E5B36B669AD,
	0x7CD35BE4BB5966F2,
	0xF2CDA59A6F3C96E9,
	0x792CD6D9A6B74B76,
	0x6E92FD679B4B3C9F,
	0x96697CFA59A5B34D,
	0x4B679AFD25DACB36,
	0xB5966DACD27BE4F3,
	0xF3D96696CD3DBB4B,
	0x6B749F6B2CFA5DA4,
	0xB5B369E792CD3D9A,
	0x9E5BB4D6EB2ED659,
	0x5DAEB3696E93CF25,
	0x679E4B34B66DADD2,
	0xD37BA4BBD976D2CD,
	0xCDA59A4F3CD6696D,
	0x2ED2D9AEB74976B6,
	0x9AED65BB4F349E79,
	0x693CF2D9B5B34D6E,
	0xE69ADF25DACB3796,
	0x966D2CD379E4B74B,
	0xC966B6CD35BA5BB7,
	0x7497EB3CDA59E4FB,
	0xB34BE7D2CD2D9A6B,
	0x5B3CD7E92ED659B4,
	0xACB36D6693DF279A,
	0x9ECB34B669EDDA5D,
	0x5BA4FB5967D2ED27,
	0xAD9B4F3C9669ECD3,
	0xF2DDA6B75976B2CD,
	0xED759B4B749E792C,
	0x3CF259A5B36D6E92,
	0x9BDD25DECBB6966B,
	0x6D2CD279E6B34B6E,
	0x7696CD75BA4BB5B6,
	0xD76B2DDA79A4F3C9,
	0x49E796CDAD9A6B74,
	0x34D6F92ED659BCB3,
	0xB369669BCF25BA5F,
	0x4B35B669ADD2DDBC,
	0xA4BF59E6D2CF27DE,
	0x9A5F3E96696CD35B,
	0xD9E6BF4976B2CDA5,
	0x659B6B349EF93CD2,
	0xF659A5B34F6ED2ED,
	0xDD27DACB3E97693C,
	0x6CDA79E4B34F669A,
	0x96ED35BACBB5966D,
	0x6BACDA5BA4F3C967,
	0xE792CD2D9B6B7497,
	0xDEE92EF65DB4B359,
	0x696693CF359A5B74,
	0xB4B66BADD25DADB3,
	0xBB596ED3CD279E4B,
	0x4F3CB66D6CD35BA6,
	0xA6B7C976B2CDE59A,
	0x9B4B34DE792DD2F9,
	0x59ADB34D6E96EDE5,
	0x25FACF3696793EF2,
	0xD2F9F4B34B669ADD,
	0xCF35FA4BB5966D2C,
	0x2CDB59A4F7C9E696,
	0xB2CD2D9A7B76976B,
	0xE93ED659F4BB49E7,
	0x66D3CF259A7B34D6,
	0xB769ADD65DACB36B,
	0x5D66D2DD279E4B3C,
	0x3C96696CDB5BA4BB,
	0xF74977B2EDA59ACF,
	0x4B349E79ACD2DBA6,
	0xA5B35D6E92ED6D9B,
	0xDACB769E693CF25D,
	0x79E5B36B669ADD35,
	0x35BE4BB5966F2CD2,
	0xDA59A6F3C96E97CD,
	0xCD6D9A6B74B76F2C,
	0x2FD679B4B3C9F792,
	0x97CFA59A5B34D6E9,
	0x79AFD25DACB36966,
	0x66DACD27BE4F34B6,
	0x96696CD3DBB4BB59,
	0x49F6B2CFA5DA4F3D,
	0x369E792CD3D9A6B7,
	0xBB4D6EB2ED659B5B,
	0xEB3696E93CF259E5,
	0xE4B34B66DADD25DA,
	0xBA4BBD976D2CD679,
	0x59A4F3CD6696DD37,
	0x2D9AEB74976B6CDA,
	0xD65BB4F349E792ED,
	0xCF2D9B5B34D6E9AE,
	0xADF25DACB3796693,
	0xD2CD379E4B74BE69,
	0x6B6CD35BA5BB7966,
	0x7EB3CDA59E4FBC96,
	0xBE7D2CD2D9A6B749,
	0xCD7E92ED659B4B34,
	0x36D6693DF279A5B3,
	0xB34B669EDDA5DACB,
	0x4FB5967D2ED279EC,
	0xB4F3C9669ECD35BA,
	0xDA6B75976B2CDAD9,
	0x59B4B749E792CF2D,
	0x259A5B36D6E92ED7,
	0xD25DECBB6966B3CF,
	0xCD279E6B34B6E9BD,
	0x6CD75BA4BB5B66D2,
	0xB2DDA79A4F3C9769,
	0x796CDAD9A6B74D76,
	0x6F92ED659BCB349E,
	0x9669BCF25BA5F34D,
	0x5B669ADD2DDBCB36,
	0xF59E6D2CF27DE4B3,
	0xF3E96696CD35BA4B,
	0x6BF4976B2CDA59A5,
	0xB6B349EF93CD2D9E,
	0x9A5B34F6ED2ED659,
	0x7DACB3E97693CF65,
	0xA79E4B34F669ADD2,
	0xD35BACBB5966D6CD,
	0xCDA5BA4F3C96796E,
	0x2CD2D9B6B74976BA,
	0x92EF65DB4B359E79,
	0x693CF359A5B74DEE,
	0x66BADD25DADB3696,
	0x96ED3CD279E4BB4B,
	0xCB66D6CD35BA6BB5,
	0x7C976B2CDE59A4F3,
	0xB34DE792DD2F9A6B,
	0xDB34D6E96EDE59B4,
	0xACF3696793EF259A,
	0x9F4B34B669ADD25F,
	0x5FA4BB5966D2CD2F,
	0xB59A4F7C9E696CF3,
	0xD2D9A7B76976B2CD,
	0xED659F4BB49E7B2C,
	0x3CF259A7B34D6E93,
	0x9ADD65DACB36B66D,
	0x6D2DD279E4B3CB76,
	0x6696CDB5BA4BB5D6,
	0x977B2EDA59ACF3C9,
	0x49E79ACD2DBA6F74,
	0x35D6E92ED6D9B4B3,
	0xB769E693CF25DA5B,
	0x5B36B669ADD35DAC,
	0xE4BB5966F2CD279E,
	0x9A6F3C96E97CD35B,
	0xD9A6B74B76F2CDA5,
	0x679B4B3C9F792CD6,
	0xFA59A5B34D6E92FD,
	0xFD25DACB3696697C,
	0xACD27BE4F34B679A,
	0x96CD3DBB4BB5966D,
	0x6B2CFA5DA4F3D966,
	0xE792CD3D9A6B749F,
	0xD6EB2ED659B5B369,
	0x696E93CF259E5BB4,
	0x34B66DADD25DAEB3,
	0xBBD976D2CD679E4B,
	0x4F3CD6696DD37BA4,
	0xAEB74976B6CDA59A,
	0xBB4F349E792ED2D9,
	0xD9B5B34D6E9AED65,
	0x25DACB3796693CF2,
	0xD379E4B74BE69ADF,
	0xCD35BA5BB7966D2C,
	0x3CDA59E4FBC966B6,
	0xD2CD2D9A6B7497EB,
	0xE92ED659B4B34BE7,
	0x6693DF279A5B3CD7,
	0xB669EDDA5DACB36D,
	0x5967D2ED279ECB34,
	0x3C9669ECD35BA4FB,
	0xB75976B2CDAD9B4F,
	0x4B749E792CF2DDA6,
	0xA5B36D6E92ED759B,
	0xDECBB6966B3CF259,
	0x79E6B34B6E9BDD25,
	0x75BA4BB5B66D2CD2,
	0xDA79A4F3C97696CD,
	0xCDAD9A6B74D76B2D,
	0x2ED659BCB349E796,
	0x9BCF25BA5F34D6F9,
	0x69ADD2DDBCB36966,
	0xE6D2CF27DE4B35B6,
	0x96696CD35BA4BF59,
	0x4976B2CDA59A5F3E,
	0x349EF93CD2D9E6BF,
	0xB34F6ED2ED659B6B,
	0xCB3E97693CF659A5,
	0xE4B34F669ADD27DA,
	0xBACBB5966D6CDA79,
	0x5BA4F3C96796ED35,
	0x2D9B6B74976BACDA,
	0xF65DB4B359E792CD,
	0xCF359A5B74DEE92E,
	0xADD25DADB3696693,
	0xD3CD279E4BB4B66B,
	0x6D6CD35BA6BB596E,
	0x76B2CDE59A4F3CB6,
	0xDE792DD2F9A6B7C9,
	0x4D6E96EDE59B4B34,
	0x3696793EF259ADB3,
	0xB34B669ADD25FACF,
	0x4BB5966D2CD2F9F4,
	0xA4F7C9E696CF35FA,
	0x9A7B76976B2CDB59,
	0x59F4BB49E7B2CD2D,
	0x259A7B34D6E93ED6,
	0xD65DACB36B66D3CF,
	0xDD279E4B3CB769AD,
	0x6CDB5BA4BB5D66D2,
	0xB2EDA59ACF3C9669,
	0x79ACD2DBA6F74977,
	0x6E92ED6D9B4B349E,
	0x9E693CF25DA5B35D,
	0x6B669ADD35DACB76,
	0xB5966F2CD279E5B3,
	0xF3C96E97CD35BE4B,
	0x6B74B76F2CDA59A6,
	0xB4B3C9F792CD6D9A,
	0x9A5B34D6E92FD679,
	0x5DACB3696697CFA5,
	0x27BE4F34B679AFD2,
	0xD3DBB4BB5966DACD,
	0xCFA5DA4F3D96696C,
	0x2CD3D9A6B749F6B2,
	0xB2ED659B5B369E79,
	0xE93CF259E5BB4D6E,
	0x66DADD25DAEB3696,
	0x976D2CD679E4B34B,
	0xCD6696DD37BA4BBD,
	0x74976B6CDA59A4F3,
	0xF349E792ED2D9AEB,
	0x5B34D6E9AED65BB4,
	0xACB3796693CF2D9B,
	0x9E4B74BE69ADF25D,
	0x5BA5BB7966D2CD37,
	0xA59E4FBC966B6CD3,
	0xD2D9A6B7497EB3CD,
	0xED659B4B34BE7D2C,
	0x3DF279A5B3CD7E92,
	0x9EDDA5DACB36D669,
	0x7D2ED279ECB34B66,
	0x669ECD35BA4FB596,
	0x976B2CDAD9B4F3C9,
	0x49E792CF2DDA6B75,
	0x36D6E92ED759B4B7,
	0xBB6966B3CF259A5B,
	0x6B34B6E9BDD25DEC,
	0xA4BB5B66D2CD279E,
	0x9A4F3C97696CD75B,
	0xD9A6B74D76B2DDA7,
	0x659BCB349E796CDA,
	0xF25BA5F34D6F92ED,
	0xDD2DDBCB369669BC,
	0x2CF27DE4B35B669A,
	0x96CD35BA4BF59E6D,
	0x6B2CDA59A5F3E966,
	0xEF93CD2D9E6BF497,
	0xF6ED2ED659B6B349,
	0xE97693CF659A5B34,
	0x34F669ADD27DACB3,
	0xBB5966D6CDA79E4B,
	0x4F3C96796ED35BAC,
	0xB6B74976BACDA5BA,
	0xDB4B359E792CD2D9,
	0x59A5B74DEE92EF65,
	0x25DADB3696693CF3,
	0xD279E4BB4B66BADD,
	0xCD35BA6BB596ED3C,
	0x2CDE59A4F3CB66D6,
	0x92DD2F9A6B7C976B,
	0xE96EDE59B4B34DE7,
	0x6793EF259ADB34D6,
	0xB669ADD25FACF369,
	0x5966D2CD2F9F4B34,
	0x7C9E696CF35FA4BB,
	0xB76976B2CDB59A4F,
	0x4BB49E7B2CD2D9A7,
	0xA7B34D6E93ED659F,
	0xDACB36B66D3CF259,
	0x79E4B3CB769ADD65,
	0xB5BA4BB5D66D2DD2,
	0xDA59ACF3C96696CD,
	0xCD2DBA6F74977B2E,
	0x2ED6D9B4B349E79A,
	0x93CF25DA5B35D6E9,
	0x69ADD35DACB769E6,
	0x66F2CD279E5B36B6,
	0x96E97CD35BE4BB59,
	0x4B76F2CDA59A6F3C,
	0x3C9F792CD6D9A6B7,
	0xB34D6E92FD679B4B,
	0xCB3696697CFA59A5,
	0xE4F34B679AFD25DA,
	0xBB4BB5966DACD27B,
	0x5DA4F3D96696CD3D,
	0x3D9A6B749F6B2CFA,
	0xD659B5B369E792CD,
	0xCF259E5BB4D6EB2E,
	0xADD25DAEB3696E93,
	0xD2CD679E4B34B66D,
	0x696DD37BA4BBD976,
	0x76B6CDA59A4F3CD6,
	0x9E792ED2D9AEB749,
	0x4D6E9AED65BB4F34,
	0x3796693CF2D9B5B3,
	0xB74BE69ADF25DACB,
	0x5BB7966D2CD379E4,
	0xE4FBC966B6CD35BA,
	0x9A6B7497EB3CDA59,
	0x59B4B34BE7D2CD2D,
	0x279A5B3CD7E92ED6,
	0xDA5DACB36D6693DF,
	0xED279ECB34B669ED,
	0xECD35BA4FB5967D2,
	0xB2CDAD9B4F3C9669,
	0x792CF2DDA6B75976,
	0x6E92ED759B4B749E,
	0x966B3CF259A5B36D,
	0x4B6E9BDD25DECBB6,
	0xB5B66D2CD279E6B3,
	0xF3C97696CD75BA4B,
	0x6B74D76B2DDA79A4,
	0xBCB349E796CDAD9A,
	0xBA5F34D6F92ED659,
	0xDDBCB369669BCF25,
	0x27DE4B35B669ADD2,
	0xD35BA4BF59E6D2CF,
	0xCDA59A5F3E96696C,
	0x3CD2D9E6BF4976B2,
	0xD2ED659B6B349EF9,
	0x693CF659A5B34F6E,
	0x669ADD27DACB3E97,
	0x966D6CDA79E4B34F,
	0xC96796ED35BACBB5,
	0x74976BACDA5BA4F3,
	0xB359E792CD2D9B6B,
	0x5B74DEE92EF65DB4,
	0xADB3696693CF359A,
	0x9E4BB4B66BADD25D,
	0x5BA6BB596ED3CD27,
	0xE59A4F3CB66D6CD3,
	0xD2F9A6B7C976B2CD,
	0xEDE59B4B34DE792D,
	0x3EF259ADB34D6E96,
	0x9ADD25FACF369679,
	0x6D2CD2F9F4B34B66,
	0xE696CF35FA4BB596,
	0x976B2CDB59A4F7C9,
	0x49E7B2CD2D9A7B76,
	0x34D6E93ED659F4BB,
	0xB36B66D3CF259A7B,
	0x4B3CB769ADD65DAC,
	0xA4BB5D66D2DD279E,
	0x9ACF3C96696CDB5B,
	0xDBA6F74977B2EDA5,
	0x6D9B4B349E79ACD2,
	0xF25DA5B35D6E92ED,
	0xDD35DACB769E693C,
	0x2CD279E5B36B669A,
	0x97CD35BE4BB5966F,
	0x6F2CDA59A6F3C96E,
	0xF792CD6D9A6B74B7,
	0xD6E92FD679B4B3C9,
	0x696697CFA59A5B34,
	0x34B679AFD25DACB3,
	0xBB5966DACD27BE4F,
	0x4F3D96696CD3DBB4,
	0xA6B749F6B2CFA5DA,
	0x9B5B369E792CD3D9,
	0x59E5BB4D6EB2ED65,
	0x25DAEB3696E93CF2,
	0xD679E4B34B66DADD,
	0xDD37BA4BBD976D2C,
	0x6CDA59A4F3CD6696,
	0x92ED2D9AEB74976B,
	0xE9AED65BB4F349E7,
	0x6693CF2D9B5B34D6,
	0xBE69ADF25DACB379,
	0x7966D2CD379E4B74,
	0xBC966B6CD35BA5BB,
	0xB7497EB3CDA59E4F,
	0x4B34BE7D2CD2D9A6,
	0xA5B3CD7E92ED659B,
	0xDACB36D6693DF279,
	0x79ECB34B669EDDA5,
	0x35BA4FB5967D2ED2,
	0xDAD9B4F3C9669ECD,
	0xCF2DDA6B75976B2C,
	0x2ED759B4B749E792,
	0xB3CF259A5B36D6E9,
	0xE9BDD25DECBB6966,
	0x66D2CD279E6B34B6,
	0x97696CD75BA4BB5B,
	0x4D76B2DDA79A4F3C,
	0x349E796CDAD9A6B7,
	0xF34D6F92ED659BCB,
	0xCB369669BCF25BA5,
	0xE4B35B669ADD2DDB,
	0xBA4BF59E6D2CF27D,
	0x59A5F3E96696CD35,
	0x2D9E6BF4976B2CDA,
	0xD659B6B349EF93CD,
	0xCF659A5B34F6ED2E,
	0xADD27DACB3E97693,
	0xD6CDA79E4B34F669,
	0x796ED35BACBB5966,
	0x76BACDA5BA4F3C96,
	0x9E792CD2D9B6B749,
	0x4DEE92EF65DB4B35,
	0x3696693CF359A5B7,
	0xBB4B66BADD25DADB,
	0x6BB596ED3CD279E4,
	0xA4F3CB66D6CD35BA,
	0x9A6B7C976B2CDE59,
	0x59B4B34DE792DD2F,
	0x259ADB34D6E96EDE,
	0xD25FACF3696793EF,
	0xCD2F9F4B34B669AD,
	0x6CF35FA4BB5966D2,
	0xB2CDB59A4F7C9E69,
	0x7B2CD2D9A7B76976,
	0x6E93ED659F4BB49E,
	0xB66D3CF259A7B34D,
	0xCB769ADD65DACB36,
	0xB5D66D2DD279E4B3,
	0xF3C96696CDB5BA4B,
	0x6F74977B2EDA59AC,
	0xB4B349E79ACD2DBA,
	0xDA5B35D6E92ED6D9,
	0x5DACB769E693CF25,
	0x279E5B36B669ADD3,
	0xD35BE4BB5966F2CD,
	0xCDA59A6F3C96E97C,
	0x2CD6D9A6B74B76F2,
	0x92FD679B4B3C9F79,
	0x697CFA59A5B34D6E,
	0x679AFD25DACB3696,
	0x966DACD27BE4F34B,
	0xD96696CD3DBB4BB5,
	0x749F6B2CFA5DA4F3,
	0xB369E792CD3D9A6B,
	0x5BB4D6EB2ED659B5,
	0xAEB3696E93CF259E,
	0x9E4B34B66DADD25D,
	0x7BA4BBD976D2CD67,
	0xA59A4F3CD6696DD3,
	0xD2D9AEB74976B6CD,
	0xED65BB4F349E792E,
	0x3CF2D9B5B34D6E9A,
	0x9ADF25DACB379669,
	0x6D2CD379E4B74BE6,
	0x66B6CD35BA5BB796,
	0x97EB3CDA59E4FBC9,
	0x4BE7D2CD2D9A6B74,
	0x3CD7E92ED659B4B3,
	0xB36D6693DF279A5B,
	0xCB34B669EDDA5DAC,
	0xA4FB5967D2ED279E,
	0x9B4F3C9669ECD35B,
	0xDDA6B75976B2CDAD,
	0x759B4B749E792CF2,
	0xF259A5B36D6E92ED,
	0xDD25DECBB6966B3C,
	0x2CD279E6B34B6E9B,
	0x96CD75BA4BB5B66D,
	0x6B2DDA79A4F3C976,
	0xE796CDAD9A6B74D7,
	0xD6F92ED659BCB349,
	0x69669BCF25BA5F34,
	0x35B669ADD2DDBCB3,
	0xBF59E6D2CF27DE4B,
	0x5F3E96696CD35BA4,
	0xE6BF4976B2CDA59A,
	0x9B6B349EF93CD2D9,
	0x59A5B34F6ED2ED65,
	0x27DACB3E97693CF6,
	0xDA79E4B34F669ADD,
	0xED35BACBB5966D6C,
	0xACDA5BA4F3C96796,
	0x92CD2D9B6B74976B,
	0xE92EF65DB4B359E7,
	0x6693CF359A5B74DE,
	0xB66BADD25DADB369,
	0x596ED3CD279E4BB4,
	0x3CB66D6CD35BA6BB,
	0xB7C976B2CDE59A4F,
	0x4B34DE792DD2F9A6,
	0xADB34D6E96EDE59B,
	0xFACF3696793EF259,
	0xF9F4B34B669ADD25,
	0x35FA4BB5966D2CD2,
	0xDB59A4F7C9E696CF,
	0xCD2D9A7B76976B2C,
	0x3ED659F4BB49E7B2,
	0xD3CF259A7B34D6E9,
	0x69ADD65DACB36B66,
	0x66D2DD279E4B3CB7,
	0x96696CDB5BA4BB5D,
	0x4977B2EDA59ACF3C,
	0x349E79ACD2DBA6F7,
	0xB35D6E92ED6D9B4B,
	0xCB769E693CF25DA5,
	0xE5B36B669ADD35DA,
	0xBE4BB5966F2CD279,
	0x59A6F3C96E97CD35,
	0x6D9A6B74B76F2CDA,
	0xD679B4B3C9F792CD,
	0xCFA59A5B34D6E92F,
	0xAFD25DACB3696697,
	0xDACD27BE4F34B679,
	0x696CD3DBB4BB5966,
	0xF6B2CFA5DA4F3D96,
	0x9E792CD3D9A6B749,
	0x4D6EB2ED659B5B36,
	0x3696E93CF259E5BB,
	0xB34B66DADD25DAEB,
	0x4BBD976D2CD679E4,
	0xA4F3CD6696DD37BA,
	0x9AEB74976B6CDA59,
	0x5BB4F349E792ED2D,
	0x2D9B5B34D6E9AED6,
	0xF25DACB3796693CF,
	0xCD379E4B74BE69AD,
	0x6CD35BA5BB7966D2,
	0xB3CDA59E4FBC966B,
	0x7D2CD2D9A6B7497E,
	0x7E92ED659B4B34BE,
};
