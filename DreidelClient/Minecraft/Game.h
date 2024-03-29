#pragma once
#include "PS3/System.h"
#include "wchar.h"
#pragma once

class Vec3
{
public:
	static Vec3 MAX;
	static Vec3 MIN;
	static Vec3 NEG_UNIT_X;
	static Vec3 NEG_UNIT_Y;
	static Vec3 NEG_UNIT_Z;
	static Vec3 ONE;
	static Vec3 UINT_X;
	static Vec3 UINT_Y;
	static Vec3 UINT_Z;
	static Vec3 ZERO;

public:
	float x;	// 0
	float y;	// 4
	float z;	// 8

public:
	Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
	Vec3(const BlockPos&);
	Vec3() {}
};

class Game
{
private:

	class BlockPos;

	class DataFixerUpper;
	class Timer;

	class LevelRenderer {
	public:

		char __padding000[0x19C];
		float location[3];

		virtual void LevelRenderer_Destructor(); //index 0
		virtual void LevelRenderer_Destructor_0(); //index 1
		virtual void func_14C0B50(); //index 2
		virtual void func_14C0B58(); //index 3
		virtual void func_14C0B60(); //index 4
		virtual void func_14C0B48(); //index 5
		virtual void func_14C0B68(); //index 6
		virtual void nullsub_0(); //index 7
		virtual void nullsub_1(); //index 8
		virtual void func_14C0B78(); //index 9
		virtual void func_14C0B80(); //index 10
		virtual void func_14C0B88(); //index 11
		virtual void func_14C0B90(); //index 12
		virtual void nullsub_2(); //index 13
		virtual void func_14C0B98(); //index 14
		virtual void func_14C0BA0(); //index 15
		virtual void func_14C0BA8(); //index 16
		virtual void nullsub_3(); //index 17
	};
	class MultiPlayerGameMode {
	public:

	};
	class LivingEntity {
	public:

	};
	class AxisAlignedBB { //need to reverse
	public:

	};
	class ModifiableAttributeMap {
	public:

	};
	class MultiPlayerLevel {
	public:

		int seaLevel;
		char __padding000[0x0010];
		int hash_magic;
		char __padding001[0x0008];
		uint32_t EntityList;
		uint32_t mobEntityList;

		virtual void func_14C0830(); //index 0
		virtual void func_14C0838(); //index 1
		virtual void func_14A1AC8(); //index 2
		virtual void func_14A1988(); //index 3
		virtual void func_14A1980(); //index 4
		virtual void func_14A1990(); //index 5
		virtual void func_14A1998(); //index 6
		virtual void func_14A19A0(); //index 7
		virtual void func_14A19A8(); //index 8
		virtual void func_14A19B0(); //index 9
		virtual void func_14A19B8(); //index 10
		virtual void func_14A19F0(); //index 11
		virtual void func_14A19C0(); //index 12
		virtual void func_14A19C8(); //index 13
		virtual void func_14A1A20(); //index 14
		virtual void func_14A19D0(); //index 15
		virtual void func_14A19D8(); //index 16
		virtual void func_14A19E0(); //index 17
		virtual void func_14A1A30(); //index 18
		virtual void func_14A1A00(); //index 19
		virtual void func_14A1A38(); //index 20
		virtual void func_14A1908(); //index 21
		virtual void func_14A1910(); //index 22
		virtual void func_14A18E0(); //index 23
		virtual void func_14A18E8(); //index 24
		virtual void func_14A1B60(); //index 25
		virtual void func_14A1B68(); //index 26
		virtual void func_14A1B28(); //index 27
		virtual void func_14A1B30(); //index 28
		virtual void func_14A19E8(); //index 29
		virtual void func_14A1A28(); //index 30
		virtual void func_14A19F8(); //index 31
		virtual void func_14A1A08(); //index 32
		virtual void func_14A1A10(); //index 33
		virtual void func_14A1A18(); //index 34
		virtual void nullsub_0(); //index 35
		virtual void func_14C0848(); //index 36
		virtual void func_14A18F0(); //index 37
		virtual void func_14A18F8(); //index 38
		virtual void nullsub_1(); //index 39
		virtual void func_14C0858(); //index 40
		virtual void func_14C0850(); //index 41
		virtual void func_14C0860(); //index 42
		virtual void func_14A1920(); //index 43
		virtual void func_14C08B0(); //index 44
		virtual void func_14A1930(); //index 45
		virtual void func_14A1938(); //index 46
		virtual void func_14A1940(); //index 47
		virtual void func_14A1948(); //index 48
		virtual void func_14A1950(); //index 49
		virtual void func_14A1958(); //index 50
		virtual void func_14A1960(); //index 51
		virtual void func_14A1968(); //index 52
		virtual void func_14A1970(); //index 53
		virtual void func_14A1978(); //index 54
		virtual void func_14A1A40(); //index 55
		virtual void func_14C08E0(); //index 56
		virtual void func_14C08E8(); //index 57
		virtual void func_14A1A58(); //index 58
		virtual void func_14C0880(); //index 59
		virtual void func_14C0890(); //index 60
		virtual void func_14C0898(); //index 61
		virtual void func_14A1A78(); //index 62
		virtual void func_14C0888(); //index 63
		virtual void func_14A1A88(); //index 64
		virtual void nullsub_2(); //index 65
		virtual void nullsub_3(); //index 66
		virtual void nullsub_4(); //index 67
		virtual void func_14A1AA8(); //index 68
		virtual void nullsub_5(); //index 69
		virtual void func_14A1AB8(); //index 70
		virtual void func_14A1AC0(); //index 71
		virtual void func_14C0840(); //index 72
		virtual void nullsub_6(); //index 73
		virtual void nullsub_7(); //index 74
		virtual void nullsub_8(); //index 75
		virtual void func_14A1AE0(); //index 76
		virtual void func_14C08D0(); //index 77
		virtual void func_14C08D8(); //index 78
		virtual void func_14C0870(); //index 79
		virtual void func_14A1AF8(); //index 80
		virtual void func_14A1B00(); //index 81
		virtual void func_14A1B08(); //index 82
		virtual void func_14C08A0(); //index 83
		virtual void func_14A1B18(); //index 84
		virtual void func_14C08A8(); //index 85
		virtual void func_14C08B8(); //index 86
		virtual void func_14A1B40(); //index 87
		virtual void nullsub_9(); //index 88
		virtual void func_14A1B50(); //index 89
		virtual void nullsub_10(); //index 90
		virtual void func_14C08F0(); //index 91
		virtual void func_14C0908(); //index 92
		virtual void func_14A1B78(); //index 93
		virtual void nullsub_11(); //index 94
		virtual void func_14A1B88(); //index 95
		virtual void func_14A33C8(); //index 96
		virtual void func_14A33D0(); //index 97
		virtual void func_14A33D8(); //index 98
		virtual void func_14A1B90(); //index 99
		virtual void func_14C08C0(); //index 100
		virtual void func_14C0900(); //index 101
	};
	class MultiplayerLocalPlayer { //your local player class used for online and offline, other localplayer class is useless at all times
	public:
		MultiplayerLocalPlayer* self;
		int unkptr;
		int entityId;

		char __padding000[0x0060];
		MultiPlayerLevel* pWorld;
		char __padding001[0x0054];
		double LocationX;
		double LocationY;
		double LocationZ;
		float rotYaw;
		float rotPitch;
		char __padding002[0x0004];
		LivingEntity* ridingEnt;

		/** If true, forces the World to spawn the entity and send it to clients even if the Chunk it is located in has not yet been loaded. */
		bool forceSpawn;

		/** Reference to the World object. */
		MultiPlayerLevel* pWorld1;
		char __padding004[0x0004];
		double prevPosX;
		double prevPosY;
		double prevPosZ;

		/** position of this entity, located at the center of its bounding box. */
		double posX;
		double posY;
		double posZ;

		/** Entity motion */
		double motionX;
		double motionY;
		double motionZ;

		/** Entity rotation Yaw */
		float rotationYaw;

		/** Entity rotation Pitch */
		float rotationPitch;
		float prevRotationYaw;
		float prevRotationPitch;

		/** Axis aligned bounding box. */
		AxisAlignedBB* boundingBox;
		bool onGround;

		/** True if after a move this entity has collided */
		bool isCollidedHorizontally;
		bool isCollidedVertically;
		bool isCollided;

		char __padding005[0x0008];
		float viewHeight1;
		float viewHeight2;
		char __padding006[0x0024];
		bool isInWeb;
		char __padding007[0x0002];

		/** gets set by setEntityDead, so this must be the flag whether an Entity is dead (inactive may be better term)*/
		bool isDead;

		/** How wide this entity is considered to be */
		float width;
		float height;

		/** The previous ticks distance walked multiplied by 0.6 */
		float prevDistanceWalkedModified;

		/** The distance walked multiplied by 0.6 */
		float distanceWalkedModified;
		float distanceWalkedOnStepModified;
		float fallDistance;

		int unk1;
		int nextStepDistance;
		float unkfloat1;
		float unkfloat2;

		/** The entity's X, Y, Z coordinate at the previous tick, used to calculate position during rendering routines*/
		double lastTickPosX;
		double lastTickPosY;
		double lastTickPosZ;

		/** How high this entity can step up when running into a block to try to get over it (currently make note the entity will always step up this amount and not just the amount needed)*/
		float stepHeight;

		/** Whether this entity won't clip with collision or not (make note it won't disable gravity)*/
		bool noClip = false;

		char __padding008[0x000B];
		int ticksExisted;

		/**Whether this entity is currently inside of water (if it handles water movement that is)*/
		bool inWater;

		char __padding009[0x0003];
		int hurtResistantTime;
		char unk;
		bool dontRenderFire;
		char __padding00A[0x000E];
		int chunkCoordX;
		int chunkCoordY;
		int chunkCoordZ;
		char __padding00B[0x0024];
		int timeUntilPortal;

		/** Whether the entity is inside a Portal */
		bool inPortal;
		int portalCounter;

		/** Which dimension the player is in (-1 = the Nether, 0 = normal world) */
		int dimension;

		char __padding00D[0x0018];
		const wchar_t* name;
		char __padding00E[0x0045];
		bool sliding;
		char __padding00F[0x0006];
		int ptr_tomoreptrs;
		char __padding010[0x0090];
		ModifiableAttributeMap* AttributeMap;

		virtual void destructor1(); //index 0
		virtual void destructor2(); //index 1
		virtual void nullsub_0(); //index 2
		virtual void func_14C05F0(); //index 3
		virtual void func_14A69F0(); //index 4
		virtual void sub_2387F8(); //index 5
		virtual Vec3 getPositionVector(); //Get the position vector. <b>{@code null} is not allowed!</b> If you are not an entity in the world, return 0.0D, 0.0D, 0.0D
		virtual MultiPlayerLevel* getEntityWorld(); //Get the world, if available. <b>{@code null} is not allowed!</b> If you are not an entity in the world, return the overworld
		virtual void func_149BD28(); //index 8
		virtual void func_14A6A58(); //index 9
		virtual void func_149BD38(); //index 10
		virtual void func_149BD40(); //index 11
		virtual uint32_t GetType(); //index 12
		virtual void func_14A1BB0(); //index 13
		virtual void func_14A1B98(); //index 14
		virtual void func_14A66D8(); //index 15
		virtual void preparePlayerToSpawn(); //Keeps moving the entity up so it isn't colliding with blocks and other requirements for this entity to be spawned (only actually used on players though its also on Entity)
		virtual void setDead(); //index 17
		virtual void nullsub_1(); //index 18
		virtual void func_149B760(); //index 19
		virtual void SetPosition(double x, double y, double z); //index 20
		virtual void func_14C0798(); //index 21
		virtual void onEntityUpdate(); //index 22
		virtual void func_149B778(); //index 23
		virtual void func_14A6700(); //index 24
		virtual void SetFire(uint32_t r4); //index 25
		virtual void extinguish(); //index 26
		virtual void func_14A1E50(); //index 27
		virtual void func_14C06B0(); //index 28
		virtual void func_149B7A8(); //index 29
		virtual void func_149B7B0(); //index 30
		virtual void func_14A6720(); //index 31
		virtual void func_14A6728(); //index 32
		virtual void func_14A6730(); //index 33
		virtual void func_149B7D0(); //index 34
		virtual void nullsub_2(); //index 35
		virtual void func_149B7E0(); //index 36
		virtual void func_149B7E8(); //index 37
		virtual void func_149B7F0(); //index 38
		virtual void func_149B7F8(); //index 39
		virtual void func_14C0600(); //index 40
		virtual void func_149B808(); //index 41
		virtual void func_149B810(); //index 42
		virtual bool hasNoGravity(); //index 43
		virtual void SetNoGravity(bool noGravity); //index 44
		virtual void func_149B828(); //index 45
		virtual void func_149B830(); //index 46
		virtual void func_14A69D0(); //index 47
		virtual void func_14A1BC8(); //index 48
		virtual uint32_t getCollisionBoundingBox(); //index 49
		virtual void dealFireDamage(uint32_t amount); //index 50
		virtual void func_14A6958(); //index 51
		virtual bool isInWater(); //index 52
		virtual void func_149B868(); //index 53
		virtual void func_149B870(); //index 54
		virtual void func_149B878(); //index 55
		virtual void func_14A6960(); //index 56
		virtual void spawnRunningParticles(); //index 57
		virtual void createRunningParticles(); //index 58
		virtual void func_149B898(); //index 59
		virtual void func_149B8A0(); //index 60
		virtual void func_14A1F18(); //index 61
		virtual float getBrightness(); //index 62
		virtual void setWorld(MultiPlayerLevel* mpLevel); //index 63
		virtual void setLocationAndAngles(double x, double y, double z, float yaw, float pitch); //index 64
		virtual void nullsub_3(); //index 65
		virtual void func_14A6A70(); //index 66
		virtual void func_149B8D8(); //index 67
		virtual void func_14A1FD0(); //index 68
		virtual void func_14C0788(); //index 69
		virtual void func_14C0558(); //index 70
		virtual void func_14BCC80(); //index 71
		virtual void func_14A1FC8(); //index 72
		virtual void nullsub_4(); //index 73
		virtual void func_149B910(); //index 74
		virtual void func_149B918(); //index 75
		virtual void func_14A66E0(); //index 76
		virtual void func_149B928(); //index 77
		virtual void func_149B930(); //index 78
		virtual void func_14A66E8(); //index 79
		virtual void func_149B940(); //index 80
		virtual void func_14A67D8(); //index 81
		virtual void func_14A67E0(); //index 82
		virtual void nullsub_5(); //index 83
		virtual void func_149B948(); //index 84
		virtual void func_149B950(); //index 85
		virtual void func_149B958(); //index 86
		virtual void func_149B960(); //index 87
		virtual bool IsAlive(); //index 88
		virtual void func_14C0578(); //index 89
		virtual void func_149B978(); //index 90
		virtual void func_149B980(); //index 91
		virtual void func_14C06A0(); //index 92
		virtual void func_149B990(); //index 93
		virtual void nullsub_6(); //index 94
		virtual double getRidingHeight(); //index 95
		virtual double getRideHeight(); //index 96
		virtual void func_149B9B0(); //index 97
		virtual void func_149B9B8(); //index 98
		virtual void func_14C0810(); //index 99
		virtual void func_149B9C8(); //index 100
		virtual void func_149B9D0(); //index 101
		virtual void func_149B9D8(); //index 102
		virtual void func_149B9E0(); //index 103
		virtual void func_149B9E8(); //index 104
		virtual void func_14C0550(); //index 105
		virtual void func_149B9F8(); //index 106
		virtual void func_149BA00(); //index 107
		virtual void func_149BA08(); //index 108
		virtual void func_149BA10(); //index 109
		virtual void func_14A1F80(); //index 110
		virtual void func_149BA20(); //index 111
		virtual void func_149BA28(); //index 112
		virtual void func_149BA30(); //index 113
		virtual void func_149BA38(); //index 114
		virtual void func_149BA40(); //index 115
		virtual void func_14A6738(); //index 116
		virtual void setVelocity(double x, double y, double z); //index 117
		virtual void func_14C05E8(); //index 118
		virtual void func_14A1DD8(); //index 119
		virtual void func_14A6A10(); //index 120
		virtual void func_14A6A18(); //index 121
		virtual void func_149BA78(); //index 122
		virtual void func_14A6A08(); //index 123
		virtual bool IsBurning(); //index 124
		virtual void func_149BA90(); //index 125
		virtual void func_149BA98(); //index 126
		virtual bool IsSneaking(); //index 127
		virtual void setSneaking(); //index 128
		virtual void func_149BAB0(); //index 129
		virtual void setIsIdle(); //index 130
		virtual bool IsSprinting(); //index 131
		virtual void setSprinting(bool sprint); //index 132
		virtual bool isGlowing(); //index 133
		virtual void setGlowing(bool glowingIn); //index 134
		virtual bool isInvisible(); //index 135
		virtual bool isInvisibleToPlayer(); //index 136
		virtual void func_149BAF0(); //index 137
		virtual void func_14C0768(); //index 138
		virtual void func_14C0770(); //index 139
		virtual void func_149BB08(); //index 140
		virtual void func_149BB10(); //index 141
		virtual void func_14C0560(); //index 142
		virtual void func_14A6A20(); //index 143
		virtual void func_14A6A38(); //index 144
		virtual void func_149BB30(); //index 145
		virtual void func_149BB38(); //index 146
		virtual void func_14A8500(); //index 147
		virtual void func_14A8528(); //index 148
		virtual void func_149BB50(); //index 149
		virtual void func_14A6AB0(); //index 150
		virtual void func_149B718(); //index 151
		virtual void func_149BB60(); //index 152
		virtual void onStruckByLightning(); //index 153
		virtual void func_149BB70(); //index 154
		virtual void func_14A6970(); //index 155
		virtual bool pushOutOfBlocks(double x, double y, double z); //index 156
		virtual void func_14A1E10(); //index 157
		virtual void func_14A6978(); //index 158
		virtual void func_14A69E8(); //index 159
		virtual void func_149BBA0(); //index 160
		virtual void func_149BBA8(); //index 161
		virtual void SetInvulnerable(); //index 162
		virtual void func_149BBB8(); //index 163
		virtual void func_149BBC0(); //index 164
		virtual void func_14A1FD8(); //index 165
		virtual void func_14A1FE0(); //index 166
		virtual void func_14A1FE8(); //index 167
		virtual bool canBeAttackedWithItem(); //index 168
		virtual uint32_t hitByEntity(); //index 169
		virtual void copyLocationAndAnglesFrom(uint32_t r4); //index 170
		virtual void func_14C06B8(); //index 171
		virtual void func_149BC00(); //index 172
		virtual void func_149BC08(); //index 173
		virtual bool verifyExplosion(); //index 174
		virtual uint32_t getMaxFallHeight(); //index 175
		virtual void func_149BC20(); //index 176
		virtual void func_149BC28(); //index 177
		virtual void func_149BC30(); //index 178
		virtual uint32_t doesEntityNotTriggerPressurePlate(); //index 179
		virtual bool canRenderOnFire(); //index 180
		virtual void func_149BC48(); //index 181
		virtual void func_149BC50(); //index 182
		virtual void func_149BC58(); //index 183
		virtual void func_14A6A28(); //index 184
		virtual double getRenderDistanceWeight(); //index 185
		virtual void setRenderDistanceWeight(double dist); //index 186
		virtual void func_14A69F8(); //index 187
		virtual void func_149BC88(); //index 188
		virtual void func_149BC90(); //index 189
		virtual void func_149BC98(); //index 190
		virtual void func_149BCA0(); //index 191
		virtual void func_149BCA8(); //index 192
		virtual void func_149BCB0(); //index 193
		virtual void func_14A69C8(); //index 194
		virtual void func_14C0630(); //index 195
		virtual void func_149BCC8(); //index 196
		virtual void func_149BCD0(); //index 197
		virtual void func_149BCD8(); //index 198
		virtual void func_149BCE0(); //index 199
		virtual void func_14A1F20(); //index 200
		virtual float getViewHeight(); //index 201
		virtual void func_14A6A60(); //index 202
		virtual void func_149BD48(); //index 203
		virtual void func_149BD50(); //index 204
		virtual void nullsub_7(); //index 205
		virtual void nullsub_8(); //index 206
		virtual float getRotatedYaw(); //index 207
		virtual float getMirroredYaw(); //index 208
		virtual uint32_t ignoreItemEntityData(); //index 209
		virtual void setPositionNonDirty(); //index 210
		virtual void func_149BD88(); //index 211
		virtual void func_149BD90(); //index 212
		virtual void func_149BD98(); //index 213
		virtual void func_149BDA0(); //index 214
		virtual void func_149BDA8(); //index 215
		virtual void func_149BDB0(); //index 216
		virtual void func_149BDB8(); //index 217
		virtual void func_149BDC0(); //index 218
		virtual void func_149BDC8(); //index 219
		virtual void func_149BDD0(); //index 220
		virtual void func_149BDD8(); //index 221
		virtual void func_149BDE0(); //index 222
		virtual void func_149BDE8(); //index 223
		virtual void func_149BDF0(); //index 224
		virtual void func_14A6748(); //index 225
		virtual void func_14BCC90(); //index 226
		virtual void func_149BE08(); //index 227
		virtual void nullsub_9(); //index 228
		virtual void func_149BE18(); //index 229
		virtual void func_14A6AA0(); //index 230
		virtual void func_14A20A8(); //index 231
		virtual void func_14A8530(); //index 232
		virtual void func_14A8538(); //index 233
		virtual void func_14A8540(); //index 234
		virtual void func_14A8548(); //index 235
		virtual void func_14A8550(); //index 236
		virtual void func_14A8558(); //index 237
		virtual void nullsub_10(); //index 238
		virtual void func_1492D20(); //index 239
		virtual void nullsub_11(); //index 240
		virtual void func_14C0760(); //index 241
		virtual void func_14A6AC8(); //index 242
		virtual void func_14A6AD0(); //index 243
		virtual void func_149BE38(); //index 244
		virtual void func_149BE40(); //index 245
		virtual void func_149BE48(); //index 246
		virtual void func_149BE50(); //index 247
		virtual void func_149BE58(); //index 248
		virtual void func_149BE60(); //index 249
		virtual void func_149BE68(); //index 250
		virtual void func_149BE70(); //index 251
		virtual void func_14A66D0(); //index 252
		virtual void func_14A1BD0(); //index 253
		virtual void func_14A1BD8(); //index 254
		virtual void func_14A1BE0(); //index 255
		virtual void func_14A1BE8(); //index 256
		virtual void func_14A1BF0(); //index 257
		virtual void func_14A6708(); //index 258
		virtual void func_14A6710(); //index 259
		virtual void func_14A6718(); //index 260
		virtual void frostWalk(BlockPos* pos); //index 261
		virtual bool IsChild(); //If Animal, checks if the age timer is negative
		virtual void onDeathUpdate(); //handles entity death timer, experience orb and particle creation
		virtual bool canDropLoot(); //Entity won't drop items or experience points if this returns false
		virtual void decreaseAirSupply(uint32_t r4); //index 265
		virtual void func_14A69B8(); //index 266
		virtual void func_14A69C0(); //index 267
		virtual void func_14A1C58(); //index 268
		virtual void func_14A1C60(); //index 269
		virtual void func_14A1C68(); //index 270
		virtual void func_14A1C70(); //index 271
		virtual void func_14A1C78(); //index 272
		virtual void func_14A1C80(); //index 273
		virtual void func_14A1C88(); //index 274
		virtual void func_14A1C90(); //index 275
		virtual void updatePotionEffects(); //index 276
		virtual void func_14A1CB0(); //index 277
		virtual void func_14A1CB8(); //index 278
		virtual void func_14A1CC0(); //index 279
		virtual void func_14A1CC8(); //index 280
		virtual bool isPotionActive(uint32_t potion); //index 281
		virtual uint32_t getActivePotionEffect(uint32_t potion); //index 282
		virtual void func_14A1CE0(); //index 283
		virtual void func_14A1CE8(); //index 284
		virtual bool isPotionApplicable(); //index 285
		virtual bool isEntityUndead(); //index 286
		virtual void func_14C06A8(); //index 287
		virtual void func_14A1D08(); //index 288
		virtual void func_14C07C8(); //index 289
		virtual void func_14C07D0(); //index 290
		virtual void func_14C07D8(); //index 291
		virtual void nullsub_12(); //index 292
		virtual void func_14A1D30(); //index 293
		virtual void func_14A1D38(); //index 294
		virtual void func_14A1D48(); //index 295
		virtual void func_14A6800(); //index 296
		virtual void func_14A1D58(); //index 297
		virtual void func_14A1D60(); //index 298
		virtual void func_14A1D68(); //index 299
		virtual void func_14A1D70(); //index 300
		virtual void func_14A67B0(); //index 301
		virtual void nullsub_13(); //index 302
		virtual void func_14A1D88(); //index 303
		virtual void func_14A67B8(); //index 304
		virtual void func_14A67C0(); //index 305
		virtual void func_14A6968(); //index 306
		virtual void func_14A1DA8(); //index 307
		virtual void nullsub_14(); //index 308
		virtual void func_14A1DB8(); //index 309
		virtual void func_14A1DC0(); //index 310
		virtual void func_14A1DE0(); //index 311
		virtual void func_14A6818(); //index 312
		virtual void nullsub_15(); //index 313
		virtual void func_14A1DF8(); //index 314
		virtual void func_14A1E00(); //index 315
		virtual void func_14C07B8(); //index 316
		virtual void func_14A1E18(); //index 317
		virtual void func_14A1E20(); //index 318
		virtual void func_14A1E28(); //index 319
		virtual void func_14A1E30(); //index 320
		virtual void func_14A1E38(); //index 321
		virtual void func_14C0598(); //index 322
		virtual void func_14A1E58(); //index 323
		virtual void func_14A1E60(); //index 324
		virtual void func_14A1E68(); //index 325
		virtual uint32_t getCreatureAttribute(); //index 326
		virtual void func_14A1E78(); //index 327
		virtual void func_14A1E80(); //index 328
		virtual void func_14A1E88(); //index 329
		virtual void func_14A1E90(); //index 330
		virtual void func_14A1E98(); //index 331
		virtual void func_14A6A00(); //index 332
		virtual void func_14A6980(); //index 333
		virtual void func_14A1EB0(); //index 334
		virtual void func_14A1EB8(); //index 335
		virtual void func_14A6758(); //index 336
		virtual void func_14A1EC8(); //index 337
		virtual float getJumpUpwardsMotion(); //index 338
		virtual void func_14A6938(); //index 339
		virtual void func_14A1EE8(); //index 340
		virtual void func_14A1EF0(); //index 341
		virtual void func_14A1EF8(); //index 342
		virtual float getWaterSlowDown(); //index 343
		virtual void func_14A6940(); //index 344
		virtual void func_14A1F10(); //index 345
		virtual void func_14A6948(); //index 346
		virtual void func_14A1F30(); //index 347
		virtual void func_14A1F38(); //index 348
		virtual void func_14A68F8(); //index 349
		virtual void func_14C0690(); //index 350
		virtual void onLivingUpdate(); //index 351
		virtual void func_14C0688(); //index 352
		virtual void func_14A6A78(); //index 353
		virtual void func_14A1F70(); //index 354
		virtual void func_14A1F88(); //index 355
		virtual void func_14A1F90(); //index 356
		virtual void func_14A1F98(); //index 357
		virtual void func_14A1FA8(); //index 358
		virtual void func_14A1FB0(); //index 359
		virtual bool isServerWorld(); //index 360
		virtual void func_14A6A50(); //index 361
		virtual void func_14A6A48(); //index 362
		virtual void nullsub_16(); //index 363
		virtual void nullsub_17(); //index 364
		virtual void func_14A2010(); //index 365
		virtual void func_14A6A68(); //index 366
		virtual bool isHandActive(); //index 367
		virtual uint32_t getActiveHand(); //index 368
		virtual void func_14A2028(); //index 369
		virtual void func_14C0610(); //index 370
		virtual void func_14A2040(); //index 371
		virtual void func_14C07C0(); //index 372
		virtual void func_14A2050(); //index 373
		virtual void func_14A2058(); //index 374
		virtual void func_14A2060(); //index 375
		virtual void resetActiveHand(); //index 376
		virtual void func_14A2070(); //index 377
		virtual void func_14A2078(); //index 378
		virtual void func_14A2080(); //index 379
		virtual void func_14A2088(); //index 380
		virtual void func_14A2090(); //index 381
		virtual void nullsub_18(); //index 382
		virtual void func_14A6A98(); //index 383
		virtual void func_14A66F0(); //index 384
		virtual void func_14C07E0(); //index 385
		virtual void func_14A6790(); //index 386
		virtual void func_14A6798(); //index 387
		virtual void func_14A67A0(); //index 388
		virtual void func_14A67A8(); //index 389
		virtual void func_14C0588(); //index 390
		virtual void func_14C07A8(); //index 391
		virtual void func_14C06D8(); //index 392
		virtual void func_14C06E0(); //index 393
		virtual void func_14C06E8(); //index 394
		virtual void func_14A67E8(); //index 395
		virtual void func_14A67F0(); //index 396
		virtual void func_14A6808(); //index 397
		virtual void func_14A6810(); //index 398
		virtual void func_14A6820(); //index 399
		virtual void func_14C0638(); //index 400
		virtual void nullsub_19(); //index 401
		virtual void nullsub_20(); //index 402
		virtual void func_14C0648(); //index 403
		virtual void func_14C0650(); //index 404
		virtual void func_14C0658(); //index 405
		virtual void func_14C0660(); //index 406
		virtual void func_14C0668(); //index 407
		virtual void func_14A6878(); //index 408
		virtual void func_14A6890(); //index 409
		virtual void nullsub_21(); //index 410
		virtual void func_14C0670(); //index 411
		virtual void func_14C0678(); //index 412
		virtual void func_14C07B0(); //index 413
		virtual void func_14C07F8(); //index 414
		virtual void func_14A68D8(); //index 415
		virtual void func_14A68E8(); //index 416
		virtual void func_14A68F0(); //index 417
		virtual void func_14C06C8(); //index 418
		virtual void func_14A6908(); //index 419
		virtual void func_14A6910(); //index 420
		virtual void func_14A6918(); //index 421
		virtual void func_14A6920(); //index 422
		virtual void func_14C07F0(); //index 423
		virtual void nullsub_22(); //index 424
		virtual void func_14A6950(); //index 425
		virtual void func_14A6988(); //index 426
		virtual void func_14A6990(); //index 427
		virtual void func_14A6998(); //index 428
		virtual void func_14A69A0(); //index 429
		virtual void func_14A69A8(); //index 430
		virtual void func_14A69B0(); //index 431
		virtual void func_14C05B8(); //index 432
		virtual void nullsub_23(); //index 433
		virtual bool IsSpectator(); //index 434
		virtual void func_14A6A30(); //index 435
		virtual void func_14C06F0(); //index 436
		virtual void func_14A6A80(); //index 437
		virtual void func_14A6A88(); //index 438
		virtual void func_14A6A90(); //index 439
		virtual void func_14C0710(); //index 440
		virtual void func_14A6AA8(); //index 441
		virtual void func_14C0730(); //index 442
		virtual void func_14C0738(); //index 443
		virtual void func_14C0740(); //index 444
		virtual void func_14A6AB8(); //index 445
		virtual void func_14C0720(); //index 446
		virtual void func_14C0728(); //index 447
		virtual void func_14A6AC0(); //index 448
		virtual void func_14C0750(); //index 449
		virtual void func_14C0758(); //index 450
		virtual void func_14C0718(); //index 451
		virtual void func_14C0580(); //index 452
		virtual void getPermissionLevel(); //index 453
		virtual void setPermissionLevel(uint32_t permissionLevel); //index 454
		virtual void func_14C06C0(); //index 455
		virtual void func_14C0820(); //index 456
		virtual void func_14C0828(); //index 457
		virtual void func_14C0708(); //index 458
		virtual void func_14C0748(); //index 459
		virtual void func_14C07A0(); //index 460
		virtual void func_14C07E8(); //index 461
		virtual void func_14C0800(); //index 462
		virtual void func_14C0808(); //index 463
		virtual void func_14C0818(); //index 464

	};
	class Minecraft {
	public:
		DataFixerUpper* cDataFixerUpper;
		MultiPlayerGameMode* cMultiPlayerGameMode;
		char __padding000[0x0008];
		int displayWidth;
		int displayHeight;
		int displayWidth1;
		int displayHeight1;
		Timer* cTimer;
		char __padding001[0x0008];
		MultiPlayerLevel* cMultiPlayerLevel;
		LevelRenderer* cLevelRenderer;
		MultiplayerLocalPlayer* cMultiplayerLocalPlayer;
		char __padding002[0x000C];
		MultiplayerLocalPlayer* cMultiplayerLocalPlayer1;
		char __padding003[0x0018];
		MultiPlayerGameMode* cMultiPlayerGameMode1;
		char __padding004[0x0010];
		uint32_t unknownptr[4];
		char __padding005[0x003C];
		MultiplayerLocalPlayer* cMultiplayerLocalPlayer2;
		char __padding006[0x000C];
		uint32_t unknownptr1[2];
		char __padding007[0x0028];
		uint32_t fontRenderer;
	};

	class TheMinecraft
	{
	public:
		Minecraft* theMinecraft;
		char __padding000[0x0020];
		uint32_t gameTime;
		char __padding001[0x0080];
		uint32_t FPS;
	};

	struct temp_t {
		char __padding000[0x00C8];
		Vec3 pos;
	};

private: static const uint ADDR = 0x014CF2E4;
public: static TheMinecraft get_pointer() {
	return *(TheMinecraft*)ADDR;
}
	  template<typename R, typename ... Arguments>
	  class FunctionCaller
	  {

#define MAKE_FN(address, return_type, func_name, args) \
	uint32_t func_name##opd[2] = { address, 0x014CDAB0 }; \
	using func_name##_t = return_type(*)args; \
	func_name##_t func_name = (func_name##_t)func_name##opd;

	  public: static inline R Call(long long function, Arguments... args)
	  {
		  int toc_t[2] = { function, 0x014CDAB0 };
		  R(*temp)(Arguments...) = (R(*)(Arguments...)) & toc_t;
		  return temp(args...);
	  }

	  };
public: static class Joypad
{
public: static class ButtonsPS3 {
public: typedef unsigned int ButtonBuffer;
public: const static ButtonBuffer X = 0x100,

	X = 0x100,
	O = 0x200,
	SQUARE = 0x400,
	TRIANGLE = 0x800,
	UP = 0x40000,
	DOWN = 0x80000,
	LEFT = 0x100000,
	RIGHT = 0x200000,
	R1 = 0x4000,
	R2 = 0x70000000,
	R3 = 0x10000,
	L1 = 0x8000,
	L2 = 0x0,
	L3 = 0x20000,
	START = 0x2000,
	SELECT = 0x1000,
	JOYSTICK_L3_UP = 0x20000000,
	JOYSTICK_L3_DOWN = 0x10000000,
	JOYSTICK_L3_LEFT = 0x00800000,
	JOYSTICK_L3_RIGHT = 0x00400000;

};
public: static uint GetJoypadState() {
	return *(uint*)(0x3000CF79);
}
public: static bool IsPressing(ButtonsPS3::ButtonBuffer buffer) {
	return(GetJoypadState() & buffer) > 0;
}

};
public: static class PlayerState {
public:static enum STATE {
	Ingame = 0,
	Died = 1,
	InWater = 2,
	Floating = 3,
	Flying = 4,
	Sprinting = 5,
	Regeneration = 6,
	InPortal,
	Collided,

};
};

public:static class GuiComponentController {
private:
	struct font_t {

		char __padd000[0x0004];
		const wchar_t* text;
		int dataType;
		char __padd001[0x0008];
		int wcstrlen;
		int wcstrlen1;
		char __padd002[0x0008];
		float unknown1;
		float unknown2;
		float unknown3;
		float unknown4;
	};
public: static font_t GetTextComponent(wchar_t* a)
{
	font_t font;
	font.text = a;
	font.dataType = 7;
	font.wcstrlen = wcslen(a);
	font.wcstrlen1 = wcslen(a) + 3;
	font.unknown1 = 1.0625f;//2.0625f
	font.unknown1 = 0.4f; //1.0f
	font.unknown1 = 1.0078125f;
	return font;

}

	  // 	MAKE_FN(0xA8B55C, void, setSingleMessage, (void* guiComponent, uint32_t r4, uint32_t a, uint32_t b));
  //	MAKE_FN(0xA8AC8C, void, addMessage, (void* guiComponent, uint32_t text, int unk_0x0, bool unk_0x1, bool unk_0x2, bool unk_0x3, bool unk_0x4));
public:static void DisplayClientMessage(const wchar_t* m) {
	FunctionCaller < uint, void*, uint32_t, int, bool, bool, bool, bool>::Call(
		0xA8AC8C, 0x00, (uint)&GuiComponentController::GetTextComponent((wchar_t*)m), 0, false, false, false, false);
}public:static void DisplayHeaderMessage(const wchar_t* m) {
	FunctionCaller <void, void*, uint32_t, uint32_t, uint32_t>::Call(
		0xA8B55C, 0x00, (uint)&GuiComponentController::GetTextComponent((wchar_t*)m), 0, 0);

}
public: static const bool MustShowArmor = (bool*)0x0090B5F0;
public: static const bool Dim = (bool*)0x0155847C;

public: static void DisableRendering() {
	*(int*)(0x00884148) = 0x41;
}
public: static void EnableRendering() {

	*(int*)(0x00884148) = 0x40;
}
public: static bool IsModalActive() {
	return (*(int*)(unsigned int)(0x3000CF68)) > 0;
}
public: static void ShowActiveBar(bool t) {
	*(int*)(0x0090FCC0) = t ? 0x40 : 0x41;
}
public: static void Reload() {
	(*(int*)(0x014CE214)) = 1;
}
};
public: static uint64_t GetGameTime() {
	auto game = get_pointer();
	return game.gameTime;
};
public: static class Player
{
public: static const bool MustPlaceBlocks = (bool*)(0x007D75A3);
public: static const PlayerState::STATE GetState() {
	auto game = Game::get_pointer();
	bool regening = game.theMinecraft->cMultiplayerLocalPlayer->hurtResistantTime != 0;

	bool died = game.theMinecraft->cMultiplayerLocalPlayer->isDead;
	bool inground = game.theMinecraft->cMultiplayerLocalPlayer->onGround;
	bool inportal = game.theMinecraft->cMultiplayerLocalPlayer->inPortal;
	bool inwater = game.theMinecraft->cMultiplayerLocalPlayer->inWater;
	bool collided = game.theMinecraft->cMultiplayerLocalPlayer->isCollided;
	bool sprint =
		((Joypad::IsPressing(Joypad::ButtonsPS3::JOYSTICK_L3_UP) ||
			(Joypad::IsPressing(Joypad::ButtonsPS3::JOYSTICK_L3_LEFT) ||
				(Joypad::IsPressing(Joypad::ButtonsPS3::JOYSTICK_L3_RIGHT)) && Joypad::IsPressing(Joypad::ButtonsPS3::L3))));
	bool sprinting = (!(GuiComponentController::IsModalActive() && GuiComponentController::Dim)) && sprint;

	if (regening)
	{
		return PlayerState::Regeneration;
	}
	else if (inportal) {
		return PlayerState::Regeneration;
	}
	else if (sprinting && collided)
	{
		return PlayerState::Sprinting;
	}
	else if (!inground) {
		return PlayerState::Floating;
	}
	else if (inwater) {
		return PlayerState::InWater;
	}
	else if (died) {
		return PlayerState::Died;
	}
	else
	{
		if (sprinting && (!collided)) {
			return PlayerState::Flying;
		}
		else
		{
			return  collided ? PlayerState::Ingame : PlayerState::Floating;
		}
	}
}

public: static const wchar_t* GetUsername() {

	auto game = get_pointer();
	return game.theMinecraft->cMultiplayerLocalPlayer->name;
}
public:static Vec3 GetPosition() {
	auto game = get_pointer();
	return Vec3(
		(float)game.theMinecraft->cMultiplayerLocalPlayer->LocationX,
		(float)game.theMinecraft->cMultiplayerLocalPlayer->LocationY,
		(float)game.theMinecraft->cMultiplayerLocalPlayer->LocationZ
	);
};
public:static Vec3 GetChunkPosition() {
	auto game = get_pointer();
	return Vec3(
		(int)game.theMinecraft->cMultiplayerLocalPlayer->chunkCoordX,
		(int)game.theMinecraft->cMultiplayerLocalPlayer->chunkCoordY,
		(int)game.theMinecraft->cMultiplayerLocalPlayer->chunkCoordZ
	);
};
public:static int GetHurtResistantTime() { return  ((TheMinecraft*)ADDR)->theMinecraft->cMultiplayerLocalPlayer->hurtResistantTime; }
public:static int GetDimension() { return  ((TheMinecraft*)ADDR)->theMinecraft->cMultiplayerLocalPlayer->dimension; }
public:static int GetId() { return  ((TheMinecraft*)ADDR)->theMinecraft->cMultiplayerLocalPlayer->entityId; }
public:static float GetFallDistance() { return  ((TheMinecraft*)ADDR)->theMinecraft->cMultiplayerLocalPlayer->fallDistance; }
public:static bool IsSpawnForced() { return  ((TheMinecraft*)ADDR)->theMinecraft->cMultiplayerLocalPlayer->forceSpawn; }
public:static uint GetType() { return  ((TheMinecraft*)ADDR)->theMinecraft->cMultiplayerLocalPlayer->GetType(); }
public:static point GetMotion() {
	point p;
	auto game = get_pointer();
	p.Append(game.theMinecraft->cMultiplayerLocalPlayer->rotationYaw, game.theMinecraft->cMultiplayerLocalPlayer->rotationPitch);
	return p;
}; 
public:static void SetMotion(int yaw, int pitch) {
	((TheMinecraft*)ADDR)->theMinecraft->cMultiplayerLocalPlayer->rotationYaw = yaw;
	((TheMinecraft*)ADDR)->theMinecraft->cMultiplayerLocalPlayer->rotationPitch = yaw;
};
public:static void SetFixedPosition(Vec3 vec) {

	auto gamePtr = ((TheMinecraft*)ADDR);
	gamePtr->theMinecraft->cMultiplayerLocalPlayer->SetPosition(vec.x, vec.y, vec.z);
	gamePtr->theMinecraft->cMultiplayerLocalPlayer->posX = vec.x;
	gamePtr->theMinecraft->cMultiplayerLocalPlayer->posY = vec.y;
	gamePtr->theMinecraft->cMultiplayerLocalPlayer->posZ = vec.z;
	gamePtr->theMinecraft->cMultiplayerLocalPlayer->LocationX = vec.x;
	gamePtr->theMinecraft->cMultiplayerLocalPlayer->LocationY = vec.y;
	gamePtr->theMinecraft->cMultiplayerLocalPlayer->LocationZ = vec.z;
	gamePtr->theMinecraft->cMultiplayerLocalPlayer->prevPosX = vec.x;
	gamePtr->theMinecraft->cMultiplayerLocalPlayer->prevPosY = vec.y;
	gamePtr->theMinecraft->cMultiplayerLocalPlayer->prevPosZ = vec.z;

}
	 

};



};

