<template>
  <div>
    <el-button type="primary" @click="dialogFormVisible = true">
      <el-icon style="margin-right: 5px;"><Plus /></el-icon>
      新增
    </el-button>

    <el-select
      placeholder="更多操作"
      style="width: 100px"
    >
      <el-option
        :label="11"
        :value="11"
        @click="dialogFormVisible = true"
      />
    </el-select>

    <!-- 对话框 -->
    <el-dialog v-model="dialogFormVisible" title="新增" width="825px">
      <el-upload
        class="upload-demo"
        drag
        action="https://run.mocky.io/v3/9d059bf9-4660-45f2-925d-ce80ad6c4d15"
        multiple
      >
        <el-icon style="margin: 10px 0;font-size: 30px;"><Plus /></el-icon>
        <div class="el-upload__text">
          上传营业执照
        </div>
      </el-upload>

      <!-- 表单 -->
      <el-form :label-position="right" :inline="true" :model="formInline" class="demo-form-inline">
        <el-form-item label="单位名称">
          <el-input v-model="formInline.user" placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="体检类型">
          <el-select
            v-model="formInline.region"
            placeholder="Activity zone"
            clearable
          >
            <el-option label="Zone one" value="shanghai" />
            <el-option label="Zone two" value="beijing" />
          </el-select>
        </el-form-item>
        <el-form-item label="统一社会信用代码">
          <el-input v-model="formInline.user" placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="行业类型">
          <el-select
            v-model="formInline.region"
            placeholder="Activity zone"
            clearable
          >
            <el-option label="Zone one" value="shanghai" />
            <el-option label="Zone two" value="beijing" />
          </el-select>
        </el-form-item>
        <el-form-item label="所属地区">
          <el-select
            v-model="formInline.region"
            placeholder="Activity zone"
            clearable
          >
            <el-option label="Zone one" value="shanghai" />
            <el-option label="Zone two" value="beijing" />
          </el-select>
        </el-form-item>
        <el-form-item label="经济类型">
          <el-select
            v-model="formInline.region"
            placeholder="Activity zone"
            clearable
          >
            <el-option label="Zone one" value="shanghai" />
            <el-option label="Zone two" value="beijing" />
          </el-select>
        </el-form-item>
        <el-form-item label="单位注册地址">
          <el-input v-model="formInline.user" placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="企业规模">
          <el-select
            v-model="formInline.region"
            placeholder="Activity zone"
            clearable
          >
            <el-option label="Zone one" value="shanghai" />
            <el-option label="Zone two" value="beijing" />
          </el-select>
        </el-form-item>
        <el-form-item label="体检联系人姓名">
          <el-input v-model="formInline.user" placeholder="Approved by" clearable />
        </el-form-item>
        <el-form-item label="体检联系人电话">
          <el-input v-model="formInline.user" placeholder="Approved by" clearable />
        </el-form-item>
        <!-- <el-form-item>
          <el-button type="primary" @click="onSubmit">Query</el-button>
        </el-form-item> -->
        <!-- 上传图片 -->
      </el-form>

      <!-- 底栏 -->
      <template #footer>
        <span class="dialog-footer">
          <el-button @click="dialogFormVisible = false">取消</el-button>
          <el-button type="primary" @click="dialogFormVisible = false">
            提交
          </el-button>
        </span>
      </template>
    </el-dialog>
  </div>
</template>

<script setup>
import { reactive, ref } from 'vue'
import { ElMessage } from 'element-plus';
import { Plus } from '@element-plus/icons-vue';

const dialogFormVisible = ref(false)

const form = reactive({
  name: '',
  region: '',
  date1: '',
  date2: '',
  delivery: false,
  type: [],
  resource: '',
  desc: '',
})


// 表单
const formInline = reactive({
  user: '',
  region: '',
  date: '',
})

const onSubmit = () => {
  console.log('submit!')
}

// 上传图片
const imageUrl = ref('');

const handleAvatarSuccess = (response, uploadFile) => {
  imageUrl.value = URL.createObjectURL(uploadFile.raw);
};

const beforeAvatarUpload = (rawFile) => {
  if (rawFile.type !== 'image/jpeg') {
    ElMessage.error('Avatar picture must be JPG format!');
    return false;
  } else if (rawFile.size / 1024 / 1024 > 2) {
    ElMessage.error('Avatar picture size cannot exceed 2MB!');
    return false;
  }
  return true;
};
</script>

<style lang="scss" scoped>
.el-button--text {
  margin-right: 15px;
}

.el-dialog {
  display: flex;
  justify-content: center;
}

.el-input,
.el-select {
  width: 180px;
}

.el-form {
  flex: 1;
  display: grid;
  grid-template-columns: repeat(2, 1fr);
  gap: 5px;
  justify-items: end;
}

.dialog-footer button:first-child {
  margin-right: 10px;
}
</style>
