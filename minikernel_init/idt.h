.globl idt_table
idt_table:
	.word interupt_000
	.word 0x0010
	.long interupt_000
	.word interupt_001
	.word 0x0010
	.long interupt_001
	.word interupt_002
	.word 0x0010
	.long interupt_002
	.word interupt_003
	.word 0x0010
	.long interupt_003
	.word interupt_004
	.word 0x0010
	.long interupt_004
	.word interupt_005
	.word 0x0010
	.long interupt_005
	.word interupt_006
	.word 0x0010
	.long interupt_006
	.word interupt_007
	.word 0x0010
	.long interupt_007
	.word interupt_008
	.word 0x0010
	.long interupt_008
	.word interupt_009
	.word 0x0010
	.long interupt_009
	.word interupt_010
	.word 0x0010
	.long interupt_010
	.word interupt_011
	.word 0x0010
	.long interupt_011
	.word interupt_012
	.word 0x0010
	.long interupt_012
	.word interupt_013
	.word 0x0010
	.long interupt_013
	.word interupt_014
	.word 0x0010
	.long interupt_014
	.word interupt_015
	.word 0x0010
	.long interupt_015
	.word interupt_016
	.word 0x0010
	.long interupt_016
	.word interupt_017
	.word 0x0010
	.long interupt_017
	.word interupt_018
	.word 0x0010
	.long interupt_018
	.word interupt_019
	.word 0x0010
	.long interupt_019
	.word interupt_020
	.word 0x0010
	.long interupt_020
	.word interupt_021
	.word 0x0010
	.long interupt_021
	.word interupt_022
	.word 0x0010
	.long interupt_022
	.word interupt_023
	.word 0x0010
	.long interupt_023
	.word interupt_024
	.word 0x0010
	.long interupt_024
	.word interupt_025
	.word 0x0010
	.long interupt_025
	.word interupt_026
	.word 0x0010
	.long interupt_026
	.word interupt_027
	.word 0x0010
	.long interupt_027
	.word interupt_028
	.word 0x0010
	.long interupt_028
	.word interupt_029
	.word 0x0010
	.long interupt_029
	.word interupt_030
	.word 0x0010
	.long interupt_030
	.word interupt_031
	.word 0x0010
	.long interupt_031
	.word interupt_032
	.word 0x0010
	.long interupt_032
	.word interupt_033
	.word 0x0010
	.long interupt_033
	.word interupt_034
	.word 0x0010
	.long interupt_034
	.word interupt_035
	.word 0x0010
	.long interupt_035
	.word interupt_036
	.word 0x0010
	.long interupt_036
	.word interupt_037
	.word 0x0010
	.long interupt_037
	.word interupt_038
	.word 0x0010
	.long interupt_038
	.word interupt_039
	.word 0x0010
	.long interupt_039
	.word interupt_040
	.word 0x0010
	.long interupt_040
	.word interupt_041
	.word 0x0010
	.long interupt_041
	.word interupt_042
	.word 0x0010
	.long interupt_042
	.word interupt_043
	.word 0x0010
	.long interupt_043
	.word interupt_044
	.word 0x0010
	.long interupt_044
	.word interupt_045
	.word 0x0010
	.long interupt_045
	.word interupt_046
	.word 0x0010
	.long interupt_046
	.word interupt_047
	.word 0x0010
	.long interupt_047
	.word interupt_048
	.word 0x0010
	.long interupt_048
	.word interupt_049
	.word 0x0010
	.long interupt_049
	.word interupt_050
	.word 0x0010
	.long interupt_050
	.word interupt_051
	.word 0x0010
	.long interupt_051
	.word interupt_052
	.word 0x0010
	.long interupt_052
	.word interupt_053
	.word 0x0010
	.long interupt_053
	.word interupt_054
	.word 0x0010
	.long interupt_054
	.word interupt_055
	.word 0x0010
	.long interupt_055
	.word interupt_056
	.word 0x0010
	.long interupt_056
	.word interupt_057
	.word 0x0010
	.long interupt_057
	.word interupt_058
	.word 0x0010
	.long interupt_058
	.word interupt_059
	.word 0x0010
	.long interupt_059
	.word interupt_060
	.word 0x0010
	.long interupt_060
	.word interupt_061
	.word 0x0010
	.long interupt_061
	.word interupt_062
	.word 0x0010
	.long interupt_062
	.word interupt_063
	.word 0x0010
	.long interupt_063
	.word interupt_064
	.word 0x0010
	.long interupt_064
	.word interupt_065
	.word 0x0010
	.long interupt_065
	.word interupt_066
	.word 0x0010
	.long interupt_066
	.word interupt_067
	.word 0x0010
	.long interupt_067
	.word interupt_068
	.word 0x0010
	.long interupt_068
	.word interupt_069
	.word 0x0010
	.long interupt_069
	.word interupt_070
	.word 0x0010
	.long interupt_070
	.word interupt_071
	.word 0x0010
	.long interupt_071
	.word interupt_072
	.word 0x0010
	.long interupt_072
	.word interupt_073
	.word 0x0010
	.long interupt_073
	.word interupt_074
	.word 0x0010
	.long interupt_074
	.word interupt_075
	.word 0x0010
	.long interupt_075
	.word interupt_076
	.word 0x0010
	.long interupt_076
	.word interupt_077
	.word 0x0010
	.long interupt_077
	.word interupt_078
	.word 0x0010
	.long interupt_078
	.word interupt_079
	.word 0x0010
	.long interupt_079
	.word interupt_080
	.word 0x0010
	.long interupt_080
	.word interupt_081
	.word 0x0010
	.long interupt_081
	.word interupt_082
	.word 0x0010
	.long interupt_082
	.word interupt_083
	.word 0x0010
	.long interupt_083
	.word interupt_084
	.word 0x0010
	.long interupt_084
	.word interupt_085
	.word 0x0010
	.long interupt_085
	.word interupt_086
	.word 0x0010
	.long interupt_086
	.word interupt_087
	.word 0x0010
	.long interupt_087
	.word interupt_088
	.word 0x0010
	.long interupt_088
	.word interupt_089
	.word 0x0010
	.long interupt_089
	.word interupt_090
	.word 0x0010
	.long interupt_090
	.word interupt_091
	.word 0x0010
	.long interupt_091
	.word interupt_092
	.word 0x0010
	.long interupt_092
	.word interupt_093
	.word 0x0010
	.long interupt_093
	.word interupt_094
	.word 0x0010
	.long interupt_094
	.word interupt_095
	.word 0x0010
	.long interupt_095
	.word interupt_096
	.word 0x0010
	.long interupt_096
	.word interupt_097
	.word 0x0010
	.long interupt_097
	.word interupt_098
	.word 0x0010
	.long interupt_098
	.word interupt_099
	.word 0x0010
	.long interupt_099
	.word interupt_100
	.word 0x0010
	.long interupt_100
	.word interupt_101
	.word 0x0010
	.long interupt_101
	.word interupt_102
	.word 0x0010
	.long interupt_102
	.word interupt_103
	.word 0x0010
	.long interupt_103
	.word interupt_104
	.word 0x0010
	.long interupt_104
	.word interupt_105
	.word 0x0010
	.long interupt_105
	.word interupt_106
	.word 0x0010
	.long interupt_106
	.word interupt_107
	.word 0x0010
	.long interupt_107
	.word interupt_108
	.word 0x0010
	.long interupt_108
	.word interupt_109
	.word 0x0010
	.long interupt_109
	.word interupt_110
	.word 0x0010
	.long interupt_110
	.word interupt_111
	.word 0x0010
	.long interupt_111
	.word interupt_112
	.word 0x0010
	.long interupt_112
	.word interupt_113
	.word 0x0010
	.long interupt_113
	.word interupt_114
	.word 0x0010
	.long interupt_114
	.word interupt_115
	.word 0x0010
	.long interupt_115
	.word interupt_116
	.word 0x0010
	.long interupt_116
	.word interupt_117
	.word 0x0010
	.long interupt_117
	.word interupt_118
	.word 0x0010
	.long interupt_118
	.word interupt_119
	.word 0x0010
	.long interupt_119
	.word interupt_120
	.word 0x0010
	.long interupt_120
	.word interupt_121
	.word 0x0010
	.long interupt_121
	.word interupt_122
	.word 0x0010
	.long interupt_122
	.word interupt_123
	.word 0x0010
	.long interupt_123
	.word interupt_124
	.word 0x0010
	.long interupt_124
	.word interupt_125
	.word 0x0010
	.long interupt_125
	.word interupt_126
	.word 0x0010
	.long interupt_126
	.word interupt_127
	.word 0x0010
	.long interupt_127
	.word interupt_128
	.word 0x0010
	.long interupt_128
	.word interupt_129
	.word 0x0010
	.long interupt_129
	.word interupt_130
	.word 0x0010
	.long interupt_130
	.word interupt_131
	.word 0x0010
	.long interupt_131
	.word interupt_132
	.word 0x0010
	.long interupt_132
	.word interupt_133
	.word 0x0010
	.long interupt_133
	.word interupt_134
	.word 0x0010
	.long interupt_134
	.word interupt_135
	.word 0x0010
	.long interupt_135
	.word interupt_136
	.word 0x0010
	.long interupt_136
	.word interupt_137
	.word 0x0010
	.long interupt_137
	.word interupt_138
	.word 0x0010
	.long interupt_138
	.word interupt_139
	.word 0x0010
	.long interupt_139
	.word interupt_140
	.word 0x0010
	.long interupt_140
	.word interupt_141
	.word 0x0010
	.long interupt_141
	.word interupt_142
	.word 0x0010
	.long interupt_142
	.word interupt_143
	.word 0x0010
	.long interupt_143
	.word interupt_144
	.word 0x0010
	.long interupt_144
	.word interupt_145
	.word 0x0010
	.long interupt_145
	.word interupt_146
	.word 0x0010
	.long interupt_146
	.word interupt_147
	.word 0x0010
	.long interupt_147
	.word interupt_148
	.word 0x0010
	.long interupt_148
	.word interupt_149
	.word 0x0010
	.long interupt_149
	.word interupt_150
	.word 0x0010
	.long interupt_150
	.word interupt_151
	.word 0x0010
	.long interupt_151
	.word interupt_152
	.word 0x0010
	.long interupt_152
	.word interupt_153
	.word 0x0010
	.long interupt_153
	.word interupt_154
	.word 0x0010
	.long interupt_154
	.word interupt_155
	.word 0x0010
	.long interupt_155
	.word interupt_156
	.word 0x0010
	.long interupt_156
	.word interupt_157
	.word 0x0010
	.long interupt_157
	.word interupt_158
	.word 0x0010
	.long interupt_158
	.word interupt_159
	.word 0x0010
	.long interupt_159
	.word interupt_160
	.word 0x0010
	.long interupt_160
	.word interupt_161
	.word 0x0010
	.long interupt_161
	.word interupt_162
	.word 0x0010
	.long interupt_162
	.word interupt_163
	.word 0x0010
	.long interupt_163
	.word interupt_164
	.word 0x0010
	.long interupt_164
	.word interupt_165
	.word 0x0010
	.long interupt_165
	.word interupt_166
	.word 0x0010
	.long interupt_166
	.word interupt_167
	.word 0x0010
	.long interupt_167
	.word interupt_168
	.word 0x0010
	.long interupt_168
	.word interupt_169
	.word 0x0010
	.long interupt_169
	.word interupt_170
	.word 0x0010
	.long interupt_170
	.word interupt_171
	.word 0x0010
	.long interupt_171
	.word interupt_172
	.word 0x0010
	.long interupt_172
	.word interupt_173
	.word 0x0010
	.long interupt_173
	.word interupt_174
	.word 0x0010
	.long interupt_174
	.word interupt_175
	.word 0x0010
	.long interupt_175
	.word interupt_176
	.word 0x0010
	.long interupt_176
	.word interupt_177
	.word 0x0010
	.long interupt_177
	.word interupt_178
	.word 0x0010
	.long interupt_178
	.word interupt_179
	.word 0x0010
	.long interupt_179
	.word interupt_180
	.word 0x0010
	.long interupt_180
	.word interupt_181
	.word 0x0010
	.long interupt_181
	.word interupt_182
	.word 0x0010
	.long interupt_182
	.word interupt_183
	.word 0x0010
	.long interupt_183
	.word interupt_184
	.word 0x0010
	.long interupt_184
	.word interupt_185
	.word 0x0010
	.long interupt_185
	.word interupt_186
	.word 0x0010
	.long interupt_186
	.word interupt_187
	.word 0x0010
	.long interupt_187
	.word interupt_188
	.word 0x0010
	.long interupt_188
	.word interupt_189
	.word 0x0010
	.long interupt_189
	.word interupt_190
	.word 0x0010
	.long interupt_190
	.word interupt_191
	.word 0x0010
	.long interupt_191
	.word interupt_192
	.word 0x0010
	.long interupt_192
	.word interupt_193
	.word 0x0010
	.long interupt_193
	.word interupt_194
	.word 0x0010
	.long interupt_194
	.word interupt_195
	.word 0x0010
	.long interupt_195
	.word interupt_196
	.word 0x0010
	.long interupt_196
	.word interupt_197
	.word 0x0010
	.long interupt_197
	.word interupt_198
	.word 0x0010
	.long interupt_198
	.word interupt_199
	.word 0x0010
	.long interupt_199
	.word interupt_200
	.word 0x0010
	.long interupt_200
	.word interupt_201
	.word 0x0010
	.long interupt_201
	.word interupt_202
	.word 0x0010
	.long interupt_202
	.word interupt_203
	.word 0x0010
	.long interupt_203
	.word interupt_204
	.word 0x0010
	.long interupt_204
	.word interupt_205
	.word 0x0010
	.long interupt_205
	.word interupt_206
	.word 0x0010
	.long interupt_206
	.word interupt_207
	.word 0x0010
	.long interupt_207
	.word interupt_208
	.word 0x0010
	.long interupt_208
	.word interupt_209
	.word 0x0010
	.long interupt_209
	.word interupt_210
	.word 0x0010
	.long interupt_210
	.word interupt_211
	.word 0x0010
	.long interupt_211
	.word interupt_212
	.word 0x0010
	.long interupt_212
	.word interupt_213
	.word 0x0010
	.long interupt_213
	.word interupt_214
	.word 0x0010
	.long interupt_214
	.word interupt_215
	.word 0x0010
	.long interupt_215
	.word interupt_216
	.word 0x0010
	.long interupt_216
	.word interupt_217
	.word 0x0010
	.long interupt_217
	.word interupt_218
	.word 0x0010
	.long interupt_218
	.word interupt_219
	.word 0x0010
	.long interupt_219
	.word interupt_220
	.word 0x0010
	.long interupt_220
	.word interupt_221
	.word 0x0010
	.long interupt_221
	.word interupt_222
	.word 0x0010
	.long interupt_222
	.word interupt_223
	.word 0x0010
	.long interupt_223
	.word interupt_224
	.word 0x0010
	.long interupt_224
	.word interupt_225
	.word 0x0010
	.long interupt_225
	.word interupt_226
	.word 0x0010
	.long interupt_226
	.word interupt_227
	.word 0x0010
	.long interupt_227
	.word interupt_228
	.word 0x0010
	.long interupt_228
	.word interupt_229
	.word 0x0010
	.long interupt_229
	.word interupt_230
	.word 0x0010
	.long interupt_230
	.word interupt_231
	.word 0x0010
	.long interupt_231
	.word interupt_232
	.word 0x0010
	.long interupt_232
	.word interupt_233
	.word 0x0010
	.long interupt_233
	.word interupt_234
	.word 0x0010
	.long interupt_234
	.word interupt_235
	.word 0x0010
	.long interupt_235
	.word interupt_236
	.word 0x0010
	.long interupt_236
	.word interupt_237
	.word 0x0010
	.long interupt_237
	.word interupt_238
	.word 0x0010
	.long interupt_238
	.word interupt_239
	.word 0x0010
	.long interupt_239
	.word interupt_240
	.word 0x0010
	.long interupt_240
	.word interupt_241
	.word 0x0010
	.long interupt_241
	.word interupt_242
	.word 0x0010
	.long interupt_242
	.word interupt_243
	.word 0x0010
	.long interupt_243
	.word interupt_244
	.word 0x0010
	.long interupt_244
	.word interupt_245
	.word 0x0010
	.long interupt_245
	.word interupt_246
	.word 0x0010
	.long interupt_246
	.word interupt_247
	.word 0x0010
	.long interupt_247
	.word interupt_248
	.word 0x0010
	.long interupt_248
	.word interupt_249
	.word 0x0010
	.long interupt_249
	.word interupt_250
	.word 0x0010
	.long interupt_250
	.word interupt_251
	.word 0x0010
	.long interupt_251
	.word interupt_252
	.word 0x0010
	.long interupt_252
	.word interupt_253
	.word 0x0010
	.long interupt_253
	.word interupt_254
	.word 0x0010
	.long interupt_254
	.word interupt_255
	.word 0x0010
	.long interupt_255

.globl interrupt_init
interrupt_init:
	movl  $idt_table+4,%edi
1:	cmpl  $idt_table+256*8+4,%edi
	jz    2f
	movw  $0x8e00,(%edi)
	addl  $8,%edi
	jmp   1b
2:	lidt idt_descr
	ret

ignore_int_mess:
	.asciz "interrupt %03d (0x%02x) is ignored\n"
	.align
ignore_int:
	cld
	pushl %ecx
	pushl %edx
	pushl %es
	pushl %ds
	movl  $(__KERNEL_DS),%ecx
	movl  %ecx,%ds
	movl  %ecx,%es
	pushl %eax
	pushl %eax
	pushl $ignore_int_mess
	pushl $sc_kernel
	call  SYMBOL_NAME(kprintf)
	addl  $16,%esp
	popl  %ds
	popl  %es
	popl  %edx
	popl  %ecx
	popl  %eax
	iret

interupt_000:
	pushl %eax
	movl  $0,%eax
	jmp   ignore_int

interupt_001:
	pushl %eax
	movl  $1,%eax
	jmp   ignore_int

interupt_002:
	pushl %eax
	movl  $2,%eax
	jmp   ignore_int

interupt_003:
	pushl %eax
	movl  $3,%eax
	jmp   ignore_int

interupt_004:
	pushl %eax
	movl  $4,%eax
	jmp   ignore_int

interupt_005:
	pushl %eax
	movl  $5,%eax
	jmp   ignore_int

interupt_006:
	pushl %eax
	movl  $6,%eax
	jmp   ignore_int

interupt_007:
	pushl %eax
	movl  $7,%eax
	jmp   ignore_int

interupt_008:
	pushl %eax
	movl  $8,%eax
	jmp   ignore_int

interupt_009:
	pushl %eax
	movl  $9,%eax
	jmp   ignore_int

interupt_010:
	pushl %eax
	movl  $10,%eax
	jmp   ignore_int

interupt_011:
	pushl %eax
	movl  $11,%eax
	jmp   ignore_int

interupt_012:
	pushl %eax
	movl  $12,%eax
	jmp   ignore_int

interupt_013:
	pushl %eax
	movl  $13,%eax
	jmp   ignore_int

interupt_014:
	pushl %eax
	movl  $14,%eax
	jmp   ignore_int

interupt_015:
	pushl %eax
	movl  $15,%eax
	jmp   ignore_int

interupt_016:
	pushl %eax
	movl  $16,%eax
	jmp   ignore_int

interupt_017:
	pushl %eax
	movl  $17,%eax
	jmp   ignore_int

interupt_018:
	pushl %eax
	movl  $18,%eax
	jmp   ignore_int

interupt_019:
	pushl %eax
	movl  $19,%eax
	jmp   ignore_int

interupt_020:
	pushl %eax
	movl  $20,%eax
	jmp   ignore_int

interupt_021:
	pushl %eax
	movl  $21,%eax
	jmp   ignore_int

interupt_022:
	pushl %eax
	movl  $22,%eax
	jmp   ignore_int

interupt_023:
	pushl %eax
	movl  $23,%eax
	jmp   ignore_int

interupt_024:
	pushl %eax
	movl  $24,%eax
	jmp   ignore_int

interupt_025:
	pushl %eax
	movl  $25,%eax
	jmp   ignore_int

interupt_026:
	pushl %eax
	movl  $26,%eax
	jmp   ignore_int

interupt_027:
	pushl %eax
	movl  $27,%eax
	jmp   ignore_int

interupt_028:
	pushl %eax
	movl  $28,%eax
	jmp   ignore_int

interupt_029:
	pushl %eax
	movl  $29,%eax
	jmp   ignore_int

interupt_030:
	pushl %eax
	movl  $30,%eax
	jmp   ignore_int

interupt_031:
	pushl %eax
	movl  $31,%eax
	jmp   ignore_int

interupt_032:
	pushl %eax
	movl  $32,%eax
	jmp   ignore_int

interupt_033:
	pushl %eax
	movl  $33,%eax
	jmp   ignore_int

interupt_034:
	pushl %eax
	movl  $34,%eax
	jmp   ignore_int

interupt_035:
	pushl %eax
	movl  $35,%eax
	jmp   ignore_int

interupt_036:
	pushl %eax
	movl  $36,%eax
	jmp   ignore_int

interupt_037:
	pushl %eax
	movl  $37,%eax
	jmp   ignore_int

interupt_038:
	pushl %eax
	movl  $38,%eax
	jmp   ignore_int

interupt_039:
	pushl %eax
	movl  $39,%eax
	jmp   ignore_int

interupt_040:
	pushl %eax
	movl  $40,%eax
	jmp   ignore_int

interupt_041:
	pushl %eax
	movl  $41,%eax
	jmp   ignore_int

interupt_042:
	pushl %eax
	movl  $42,%eax
	jmp   ignore_int

interupt_043:
	pushl %eax
	movl  $43,%eax
	jmp   ignore_int

interupt_044:
	pushl %eax
	movl  $44,%eax
	jmp   ignore_int

interupt_045:
	pushl %eax
	movl  $45,%eax
	jmp   ignore_int

interupt_046:
	pushl %eax
	movl  $46,%eax
	jmp   ignore_int

interupt_047:
	pushl %eax
	movl  $47,%eax
	jmp   ignore_int

interupt_048:
	pushl %eax
	movl  $48,%eax
	jmp   ignore_int

interupt_049:
	pushl %eax
	movl  $49,%eax
	jmp   ignore_int

interupt_050:
	pushl %eax
	movl  $50,%eax
	jmp   ignore_int

interupt_051:
	pushl %eax
	movl  $51,%eax
	jmp   ignore_int

interupt_052:
	pushl %eax
	movl  $52,%eax
	jmp   ignore_int

interupt_053:
	pushl %eax
	movl  $53,%eax
	jmp   ignore_int

interupt_054:
	pushl %eax
	movl  $54,%eax
	jmp   ignore_int

interupt_055:
	pushl %eax
	movl  $55,%eax
	jmp   ignore_int

interupt_056:
	pushl %eax
	movl  $56,%eax
	jmp   ignore_int

interupt_057:
	pushl %eax
	movl  $57,%eax
	jmp   ignore_int

interupt_058:
	pushl %eax
	movl  $58,%eax
	jmp   ignore_int

interupt_059:
	pushl %eax
	movl  $59,%eax
	jmp   ignore_int

interupt_060:
	pushl %eax
	movl  $60,%eax
	jmp   ignore_int

interupt_061:
	pushl %eax
	movl  $61,%eax
	jmp   ignore_int

interupt_062:
	pushl %eax
	movl  $62,%eax
	jmp   ignore_int

interupt_063:
	pushl %eax
	movl  $63,%eax
	jmp   ignore_int

interupt_064:
	pushl %eax
	movl  $64,%eax
	jmp   ignore_int

interupt_065:
	pushl %eax
	movl  $65,%eax
	jmp   ignore_int

interupt_066:
	pushl %eax
	movl  $66,%eax
	jmp   ignore_int

interupt_067:
	pushl %eax
	movl  $67,%eax
	jmp   ignore_int

interupt_068:
	pushl %eax
	movl  $68,%eax
	jmp   ignore_int

interupt_069:
	pushl %eax
	movl  $69,%eax
	jmp   ignore_int

interupt_070:
	pushl %eax
	movl  $70,%eax
	jmp   ignore_int

interupt_071:
	pushl %eax
	movl  $71,%eax
	jmp   ignore_int

interupt_072:
	pushl %eax
	movl  $72,%eax
	jmp   ignore_int

interupt_073:
	pushl %eax
	movl  $73,%eax
	jmp   ignore_int

interupt_074:
	pushl %eax
	movl  $74,%eax
	jmp   ignore_int

interupt_075:
	pushl %eax
	movl  $75,%eax
	jmp   ignore_int

interupt_076:
	pushl %eax
	movl  $76,%eax
	jmp   ignore_int

interupt_077:
	pushl %eax
	movl  $77,%eax
	jmp   ignore_int

interupt_078:
	pushl %eax
	movl  $78,%eax
	jmp   ignore_int

interupt_079:
	pushl %eax
	movl  $79,%eax
	jmp   ignore_int

interupt_080:
	pushl %eax
	movl  $80,%eax
	jmp   ignore_int

interupt_081:
	pushl %eax
	movl  $81,%eax
	jmp   ignore_int

interupt_082:
	pushl %eax
	movl  $82,%eax
	jmp   ignore_int

interupt_083:
	pushl %eax
	movl  $83,%eax
	jmp   ignore_int

interupt_084:
	pushl %eax
	movl  $84,%eax
	jmp   ignore_int

interupt_085:
	pushl %eax
	movl  $85,%eax
	jmp   ignore_int

interupt_086:
	pushl %eax
	movl  $86,%eax
	jmp   ignore_int

interupt_087:
	pushl %eax
	movl  $87,%eax
	jmp   ignore_int

interupt_088:
	pushl %eax
	movl  $88,%eax
	jmp   ignore_int

interupt_089:
	pushl %eax
	movl  $89,%eax
	jmp   ignore_int

interupt_090:
	pushl %eax
	movl  $90,%eax
	jmp   ignore_int

interupt_091:
	pushl %eax
	movl  $91,%eax
	jmp   ignore_int

interupt_092:
	pushl %eax
	movl  $92,%eax
	jmp   ignore_int

interupt_093:
	pushl %eax
	movl  $93,%eax
	jmp   ignore_int

interupt_094:
	pushl %eax
	movl  $94,%eax
	jmp   ignore_int

interupt_095:
	pushl %eax
	movl  $95,%eax
	jmp   ignore_int

interupt_096:
	pushl %eax
	movl  $96,%eax
	jmp   ignore_int

interupt_097:
	pushl %eax
	movl  $97,%eax
	jmp   ignore_int

interupt_098:
	pushl %eax
	movl  $98,%eax
	jmp   ignore_int

interupt_099:
	pushl %eax
	movl  $99,%eax
	jmp   ignore_int

interupt_100:
	pushl %eax
	movl  $100,%eax
	jmp   ignore_int

interupt_101:
	pushl %eax
	movl  $101,%eax
	jmp   ignore_int

interupt_102:
	pushl %eax
	movl  $102,%eax
	jmp   ignore_int

interupt_103:
	pushl %eax
	movl  $103,%eax
	jmp   ignore_int

interupt_104:
	pushl %eax
	movl  $104,%eax
	jmp   ignore_int

interupt_105:
	pushl %eax
	movl  $105,%eax
	jmp   ignore_int

interupt_106:
	pushl %eax
	movl  $106,%eax
	jmp   ignore_int

interupt_107:
	pushl %eax
	movl  $107,%eax
	jmp   ignore_int

interupt_108:
	pushl %eax
	movl  $108,%eax
	jmp   ignore_int

interupt_109:
	pushl %eax
	movl  $109,%eax
	jmp   ignore_int

interupt_110:
	pushl %eax
	movl  $110,%eax
	jmp   ignore_int

interupt_111:
	pushl %eax
	movl  $111,%eax
	jmp   ignore_int

interupt_112:
	pushl %eax
	movl  $112,%eax
	jmp   ignore_int

interupt_113:
	pushl %eax
	movl  $113,%eax
	jmp   ignore_int

interupt_114:
	pushl %eax
	movl  $114,%eax
	jmp   ignore_int

interupt_115:
	pushl %eax
	movl  $115,%eax
	jmp   ignore_int

interupt_116:
	pushl %eax
	movl  $116,%eax
	jmp   ignore_int

interupt_117:
	pushl %eax
	movl  $117,%eax
	jmp   ignore_int

interupt_118:
	pushl %eax
	movl  $118,%eax
	jmp   ignore_int

interupt_119:
	pushl %eax
	movl  $119,%eax
	jmp   ignore_int

interupt_120:
	pushl %eax
	movl  $120,%eax
	jmp   ignore_int

interupt_121:
	pushl %eax
	movl  $121,%eax
	jmp   ignore_int

interupt_122:
	pushl %eax
	movl  $122,%eax
	jmp   ignore_int

interupt_123:
	pushl %eax
	movl  $123,%eax
	jmp   ignore_int

interupt_124:
	pushl %eax
	movl  $124,%eax
	jmp   ignore_int

interupt_125:
	pushl %eax
	movl  $125,%eax
	jmp   ignore_int

interupt_126:
	pushl %eax
	movl  $126,%eax
	jmp   ignore_int

interupt_127:
	pushl %eax
	movl  $127,%eax
	jmp   ignore_int

interupt_128:
	pushl %eax
	movl  $128,%eax
	jmp   ignore_int

interupt_129:
	pushl %eax
	movl  $129,%eax
	jmp   ignore_int

interupt_130:
	pushl %eax
	movl  $130,%eax
	jmp   ignore_int

interupt_131:
	pushl %eax
	movl  $131,%eax
	jmp   ignore_int

interupt_132:
	pushl %eax
	movl  $132,%eax
	jmp   ignore_int

interupt_133:
	pushl %eax
	movl  $133,%eax
	jmp   ignore_int

interupt_134:
	pushl %eax
	movl  $134,%eax
	jmp   ignore_int

interupt_135:
	pushl %eax
	movl  $135,%eax
	jmp   ignore_int

interupt_136:
	pushl %eax
	movl  $136,%eax
	jmp   ignore_int

interupt_137:
	pushl %eax
	movl  $137,%eax
	jmp   ignore_int

interupt_138:
	pushl %eax
	movl  $138,%eax
	jmp   ignore_int

interupt_139:
	pushl %eax
	movl  $139,%eax
	jmp   ignore_int

interupt_140:
	pushl %eax
	movl  $140,%eax
	jmp   ignore_int

interupt_141:
	pushl %eax
	movl  $141,%eax
	jmp   ignore_int

interupt_142:
	pushl %eax
	movl  $142,%eax
	jmp   ignore_int

interupt_143:
	pushl %eax
	movl  $143,%eax
	jmp   ignore_int

interupt_144:
	pushl %eax
	movl  $144,%eax
	jmp   ignore_int

interupt_145:
	pushl %eax
	movl  $145,%eax
	jmp   ignore_int

interupt_146:
	pushl %eax
	movl  $146,%eax
	jmp   ignore_int

interupt_147:
	pushl %eax
	movl  $147,%eax
	jmp   ignore_int

interupt_148:
	pushl %eax
	movl  $148,%eax
	jmp   ignore_int

interupt_149:
	pushl %eax
	movl  $149,%eax
	jmp   ignore_int

interupt_150:
	pushl %eax
	movl  $150,%eax
	jmp   ignore_int

interupt_151:
	pushl %eax
	movl  $151,%eax
	jmp   ignore_int

interupt_152:
	pushl %eax
	movl  $152,%eax
	jmp   ignore_int

interupt_153:
	pushl %eax
	movl  $153,%eax
	jmp   ignore_int

interupt_154:
	pushl %eax
	movl  $154,%eax
	jmp   ignore_int

interupt_155:
	pushl %eax
	movl  $155,%eax
	jmp   ignore_int

interupt_156:
	pushl %eax
	movl  $156,%eax
	jmp   ignore_int

interupt_157:
	pushl %eax
	movl  $157,%eax
	jmp   ignore_int

interupt_158:
	pushl %eax
	movl  $158,%eax
	jmp   ignore_int

interupt_159:
	pushl %eax
	movl  $159,%eax
	jmp   ignore_int

interupt_160:
	pushl %eax
	movl  $160,%eax
	jmp   ignore_int

interupt_161:
	pushl %eax
	movl  $161,%eax
	jmp   ignore_int

interupt_162:
	pushl %eax
	movl  $162,%eax
	jmp   ignore_int

interupt_163:
	pushl %eax
	movl  $163,%eax
	jmp   ignore_int

interupt_164:
	pushl %eax
	movl  $164,%eax
	jmp   ignore_int

interupt_165:
	pushl %eax
	movl  $165,%eax
	jmp   ignore_int

interupt_166:
	pushl %eax
	movl  $166,%eax
	jmp   ignore_int

interupt_167:
	pushl %eax
	movl  $167,%eax
	jmp   ignore_int

interupt_168:
	pushl %eax
	movl  $168,%eax
	jmp   ignore_int

interupt_169:
	pushl %eax
	movl  $169,%eax
	jmp   ignore_int

interupt_170:
	pushl %eax
	movl  $170,%eax
	jmp   ignore_int

interupt_171:
	pushl %eax
	movl  $171,%eax
	jmp   ignore_int

interupt_172:
	pushl %eax
	movl  $172,%eax
	jmp   ignore_int

interupt_173:
	pushl %eax
	movl  $173,%eax
	jmp   ignore_int

interupt_174:
	pushl %eax
	movl  $174,%eax
	jmp   ignore_int

interupt_175:
	pushl %eax
	movl  $175,%eax
	jmp   ignore_int

interupt_176:
	pushl %eax
	movl  $176,%eax
	jmp   ignore_int

interupt_177:
	pushl %eax
	movl  $177,%eax
	jmp   ignore_int

interupt_178:
	pushl %eax
	movl  $178,%eax
	jmp   ignore_int

interupt_179:
	pushl %eax
	movl  $179,%eax
	jmp   ignore_int

interupt_180:
	pushl %eax
	movl  $180,%eax
	jmp   ignore_int

interupt_181:
	pushl %eax
	movl  $181,%eax
	jmp   ignore_int

interupt_182:
	pushl %eax
	movl  $182,%eax
	jmp   ignore_int

interupt_183:
	pushl %eax
	movl  $183,%eax
	jmp   ignore_int

interupt_184:
	pushl %eax
	movl  $184,%eax
	jmp   ignore_int

interupt_185:
	pushl %eax
	movl  $185,%eax
	jmp   ignore_int

interupt_186:
	pushl %eax
	movl  $186,%eax
	jmp   ignore_int

interupt_187:
	pushl %eax
	movl  $187,%eax
	jmp   ignore_int

interupt_188:
	pushl %eax
	movl  $188,%eax
	jmp   ignore_int

interupt_189:
	pushl %eax
	movl  $189,%eax
	jmp   ignore_int

interupt_190:
	pushl %eax
	movl  $190,%eax
	jmp   ignore_int

interupt_191:
	pushl %eax
	movl  $191,%eax
	jmp   ignore_int

interupt_192:
	pushl %eax
	movl  $192,%eax
	jmp   ignore_int

interupt_193:
	pushl %eax
	movl  $193,%eax
	jmp   ignore_int

interupt_194:
	pushl %eax
	movl  $194,%eax
	jmp   ignore_int

interupt_195:
	pushl %eax
	movl  $195,%eax
	jmp   ignore_int

interupt_196:
	pushl %eax
	movl  $196,%eax
	jmp   ignore_int

interupt_197:
	pushl %eax
	movl  $197,%eax
	jmp   ignore_int

interupt_198:
	pushl %eax
	movl  $198,%eax
	jmp   ignore_int

interupt_199:
	pushl %eax
	movl  $199,%eax
	jmp   ignore_int

interupt_200:
	pushl %eax
	movl  $200,%eax
	jmp   ignore_int

interupt_201:
	pushl %eax
	movl  $201,%eax
	jmp   ignore_int

interupt_202:
	pushl %eax
	movl  $202,%eax
	jmp   ignore_int

interupt_203:
	pushl %eax
	movl  $203,%eax
	jmp   ignore_int

interupt_204:
	pushl %eax
	movl  $204,%eax
	jmp   ignore_int

interupt_205:
	pushl %eax
	movl  $205,%eax
	jmp   ignore_int

interupt_206:
	pushl %eax
	movl  $206,%eax
	jmp   ignore_int

interupt_207:
	pushl %eax
	movl  $207,%eax
	jmp   ignore_int

interupt_208:
	pushl %eax
	movl  $208,%eax
	jmp   ignore_int

interupt_209:
	pushl %eax
	movl  $209,%eax
	jmp   ignore_int

interupt_210:
	pushl %eax
	movl  $210,%eax
	jmp   ignore_int

interupt_211:
	pushl %eax
	movl  $211,%eax
	jmp   ignore_int

interupt_212:
	pushl %eax
	movl  $212,%eax
	jmp   ignore_int

interupt_213:
	pushl %eax
	movl  $213,%eax
	jmp   ignore_int

interupt_214:
	pushl %eax
	movl  $214,%eax
	jmp   ignore_int

interupt_215:
	pushl %eax
	movl  $215,%eax
	jmp   ignore_int

interupt_216:
	pushl %eax
	movl  $216,%eax
	jmp   ignore_int

interupt_217:
	pushl %eax
	movl  $217,%eax
	jmp   ignore_int

interupt_218:
	pushl %eax
	movl  $218,%eax
	jmp   ignore_int

interupt_219:
	pushl %eax
	movl  $219,%eax
	jmp   ignore_int

interupt_220:
	pushl %eax
	movl  $220,%eax
	jmp   ignore_int

interupt_221:
	pushl %eax
	movl  $221,%eax
	jmp   ignore_int

interupt_222:
	pushl %eax
	movl  $222,%eax
	jmp   ignore_int

interupt_223:
	pushl %eax
	movl  $223,%eax
	jmp   ignore_int

interupt_224:
	pushl %eax
	movl  $224,%eax
	jmp   ignore_int

interupt_225:
	pushl %eax
	movl  $225,%eax
	jmp   ignore_int

interupt_226:
	pushl %eax
	movl  $226,%eax
	jmp   ignore_int

interupt_227:
	pushl %eax
	movl  $227,%eax
	jmp   ignore_int

interupt_228:
	pushl %eax
	movl  $228,%eax
	jmp   ignore_int

interupt_229:
	pushl %eax
	movl  $229,%eax
	jmp   ignore_int

interupt_230:
	pushl %eax
	movl  $230,%eax
	jmp   ignore_int

interupt_231:
	pushl %eax
	movl  $231,%eax
	jmp   ignore_int

interupt_232:
	pushl %eax
	movl  $232,%eax
	jmp   ignore_int

interupt_233:
	pushl %eax
	movl  $233,%eax
	jmp   ignore_int

interupt_234:
	pushl %eax
	movl  $234,%eax
	jmp   ignore_int

interupt_235:
	pushl %eax
	movl  $235,%eax
	jmp   ignore_int

interupt_236:
	pushl %eax
	movl  $236,%eax
	jmp   ignore_int

interupt_237:
	pushl %eax
	movl  $237,%eax
	jmp   ignore_int

interupt_238:
	pushl %eax
	movl  $238,%eax
	jmp   ignore_int

interupt_239:
	pushl %eax
	movl  $239,%eax
	jmp   ignore_int

interupt_240:
	pushl %eax
	movl  $240,%eax
	jmp   ignore_int

interupt_241:
	pushl %eax
	movl  $241,%eax
	jmp   ignore_int

interupt_242:
	pushl %eax
	movl  $242,%eax
	jmp   ignore_int

interupt_243:
	pushl %eax
	movl  $243,%eax
	jmp   ignore_int

interupt_244:
	pushl %eax
	movl  $244,%eax
	jmp   ignore_int

interupt_245:
	pushl %eax
	movl  $245,%eax
	jmp   ignore_int

interupt_246:
	pushl %eax
	movl  $246,%eax
	jmp   ignore_int

interupt_247:
	pushl %eax
	movl  $247,%eax
	jmp   ignore_int

interupt_248:
	pushl %eax
	movl  $248,%eax
	jmp   ignore_int

interupt_249:
	pushl %eax
	movl  $249,%eax
	jmp   ignore_int

interupt_250:
	pushl %eax
	movl  $250,%eax
	jmp   ignore_int

interupt_251:
	pushl %eax
	movl  $251,%eax
	jmp   ignore_int

interupt_252:
	pushl %eax
	movl  $252,%eax
	jmp   ignore_int

interupt_253:
	pushl %eax
	movl  $253,%eax
	jmp   ignore_int

interupt_254:
	pushl %eax
	movl  $254,%eax
	jmp   ignore_int

interupt_255:
	pushl %eax
	movl  $255,%eax
	jmp   ignore_int
