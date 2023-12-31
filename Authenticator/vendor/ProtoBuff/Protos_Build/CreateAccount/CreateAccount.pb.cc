// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CreateAccount.proto

#include "pch.h"
#include "CreateAccount.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace Database {
constexpr CreateAccount::CreateAccount(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : email_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , password_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , requestid_(0){}
struct CreateAccountDefaultTypeInternal {
  constexpr CreateAccountDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~CreateAccountDefaultTypeInternal() {}
  union {
    CreateAccount _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT CreateAccountDefaultTypeInternal _CreateAccount_default_instance_;
}  // namespace Database
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_CreateAccount_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_CreateAccount_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_CreateAccount_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_CreateAccount_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::Database::CreateAccount, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::Database::CreateAccount, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Database::CreateAccount, requestid_),
  PROTOBUF_FIELD_OFFSET(::Database::CreateAccount, email_),
  PROTOBUF_FIELD_OFFSET(::Database::CreateAccount, password_),
  2,
  0,
  1,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, -1, sizeof(::Database::CreateAccount)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::Database::_CreateAccount_default_instance_),
};

const char descriptor_table_protodef_CreateAccount_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\023CreateAccount.proto\022\010Database\"C\n\rCreat"
  "eAccount\022\021\n\trequestID\030\001 \002(\005\022\r\n\005email\030\002 \002"
  "(\t\022\020\n\010password\030\003 \002(\t"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_CreateAccount_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_CreateAccount_2eproto = {
  false, false, 100, descriptor_table_protodef_CreateAccount_2eproto, "CreateAccount.proto", 
  &descriptor_table_CreateAccount_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_CreateAccount_2eproto::offsets,
  file_level_metadata_CreateAccount_2eproto, file_level_enum_descriptors_CreateAccount_2eproto, file_level_service_descriptors_CreateAccount_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_CreateAccount_2eproto_getter() {
  return &descriptor_table_CreateAccount_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_CreateAccount_2eproto(&descriptor_table_CreateAccount_2eproto);
namespace Database {

// ===================================================================

class CreateAccount::_Internal {
 public:
  using HasBits = decltype(std::declval<CreateAccount>()._has_bits_);
  static void set_has_requestid(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_email(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_password(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000007) ^ 0x00000007) != 0;
  }
};

CreateAccount::CreateAccount(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:Database.CreateAccount)
}
CreateAccount::CreateAccount(const CreateAccount& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  email_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_email()) {
    email_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_email(), 
      GetArenaForAllocation());
  }
  password_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_password()) {
    password_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_password(), 
      GetArenaForAllocation());
  }
  requestid_ = from.requestid_;
  // @@protoc_insertion_point(copy_constructor:Database.CreateAccount)
}

void CreateAccount::SharedCtor() {
email_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
password_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
requestid_ = 0;
}

CreateAccount::~CreateAccount() {
  // @@protoc_insertion_point(destructor:Database.CreateAccount)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void CreateAccount::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  email_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  password_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CreateAccount::ArenaDtor(void* object) {
  CreateAccount* _this = reinterpret_cast< CreateAccount* >(object);
  (void)_this;
}
void CreateAccount::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CreateAccount::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void CreateAccount::Clear() {
// @@protoc_insertion_point(message_clear_start:Database.CreateAccount)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000003u) {
    if (cached_has_bits & 0x00000001u) {
      email_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      password_.ClearNonDefaultToEmpty();
    }
  }
  requestid_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CreateAccount::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required int32 requestID = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_requestid(&has_bits);
          requestid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required string email = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_email();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Database.CreateAccount.email");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required string password = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_password();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Database.CreateAccount.password");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* CreateAccount::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Database.CreateAccount)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 requestID = 1;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_requestid(), target);
  }

  // required string email = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_email().data(), static_cast<int>(this->_internal_email().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "Database.CreateAccount.email");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_email(), target);
  }

  // required string password = 3;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_password().data(), static_cast<int>(this->_internal_password().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "Database.CreateAccount.password");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_password(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Database.CreateAccount)
  return target;
}

size_t CreateAccount::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:Database.CreateAccount)
  size_t total_size = 0;

  if (_internal_has_email()) {
    // required string email = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_email());
  }

  if (_internal_has_password()) {
    // required string password = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_password());
  }

  if (_internal_has_requestid()) {
    // required int32 requestID = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_requestid());
  }

  return total_size;
}
size_t CreateAccount::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Database.CreateAccount)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000007) ^ 0x00000007) == 0) {  // All required fields are present.
    // required string email = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_email());

    // required string password = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_password());

    // required int32 requestID = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_requestid());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CreateAccount::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    CreateAccount::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CreateAccount::GetClassData() const { return &_class_data_; }

void CreateAccount::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<CreateAccount *>(to)->MergeFrom(
      static_cast<const CreateAccount &>(from));
}


void CreateAccount::MergeFrom(const CreateAccount& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Database.CreateAccount)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_email(from._internal_email());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_password(from._internal_password());
    }
    if (cached_has_bits & 0x00000004u) {
      requestid_ = from.requestid_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CreateAccount::CopyFrom(const CreateAccount& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Database.CreateAccount)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CreateAccount::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void CreateAccount::InternalSwap(CreateAccount* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &email_, lhs_arena,
      &other->email_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &password_, lhs_arena,
      &other->password_, rhs_arena
  );
  swap(requestid_, other->requestid_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CreateAccount::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_CreateAccount_2eproto_getter, &descriptor_table_CreateAccount_2eproto_once,
      file_level_metadata_CreateAccount_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Database
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Database::CreateAccount* Arena::CreateMaybeMessage< ::Database::CreateAccount >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Database::CreateAccount >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
